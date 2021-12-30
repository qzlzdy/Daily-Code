import torch
import torch.nn as nn
import torch.nn.functional as F
from random import sample, randint

device = torch.device('cpu')

class Game2048:
    def __init__(self, size):
        self.size = size
        self.grid = None
        self.score = None
        self.over = None
        self.reset()
    
    def getState(self):
        return self.grid

    def getScore(self):
        return self.score
    
    def getVector(self, action):
        idx = 0
        maxProb = 0
        for i, p in enumerate(action):
            if p > maxProb:
                idx = i
        vecs = {
            0: {'x': 0, 'y': -1},
            1: {'x': 1, 'y': 0},
            2: {'x': 0, 'y': 1},
            3: {'x': -1, 'y': 0}
        }
        return vecs[idx]

    # action: [up, right, down, left]
    def step(self, action):
        if self.over:
            return 0, True
        merged = torch.zeros([self.size, self.size], device=device, dtype=torch.bool)
        vector = self.getVector(action)
        traversals = self.buildTraversals(vector)
        moved = False
        reward = 0
        for x in traversals['x']:
            for y in traversals['y']:
                cell = {'x': x, 'y': y}
                tile = self.grid[x, y]
                if tile > 0:
                    position = self.findFarthestPosition(cell, vector)
                    nxt = position['next']
                    if self.withinBounds(nxt):
                        nextCell = self.grid[nxt['x'], nxt['y']]
                    else:
                        nextCell = None
                    if nextCell and nextCell == tile and \
                       not merged[nxt['x'], nxt['y']]:
                        merged[nxt['x'], nxt['y']] = True
                        reward = tile * 2
                        self.grid[nxt['x'], nxt['y']] = reward
                        self.grid[x, y] = 0
                        self.score += reward
                        moved = True
                    else:
                        farthest = position['farthest']
                        if farthest['x'] != cell['x'] or farthest['x'] != cell['y']:
                            reward = 1
                            self.moveTile(cell, position['farthest'])
                            moved = True
        if moved:
            self.addRandomTile()
            if not self.movesAvailable():
                self.over = True
        return reward, self.over

    def buildTraversals(self, vector):
        traversals = {
            'x': [],
            'y': []
        }
        for pos in range(self.size):
            traversals['x'].append(pos)
            traversals['y'].append(pos)
        if vector['x'] == 1:
            traversals['x'].reverse()
        if vector['y'] == 1:
            traversals['y'].reverse()
        return traversals

    def withinBounds(self, cell):
        return 0 <= cell['x'] and cell['x'] < self.size and \
               0 <= cell['y'] and cell['y'] < self.size

    def cellAvailable(self, cell):
        return self.grid[cell['x'], cell['y']] == 0

    def findFarthestPosition(self, cell, vector):
        previous = None
        while True:
            previous = cell
            cell = {
                'x': previous['x'] + vector['x'],
                'y': previous['y'] + vector['y']
            }
            if not (self.withinBounds(cell) and self.cellAvailable(cell)):
                break
        return {'farthest': previous, 'next': cell}

    def moveTile(self, tile, cell):
        self.grid[cell['x'], cell['y']] = self.grid[tile['x'], tile['y']]
        self.grid[tile['x'], tile['y']] = 0

    def movesAvailable(self):
        return self.cellsAvailable() or self.tileMatchesAvailable()

    def tileMatchesAvailable(self):
        for x in range(self.size):
            for y in range(self.size):
                tile = self.grid[x, y]
                if tile > 0:
                    for direction in torch.eye(4):
                        vector = self.getVector(direction)
                        cell = {'x': x + vector['x'], 'y': y + vector['y']}
                        other = self.grid[cell['x'], cell['y']]
                        if other > 0 and other == tile:
                            return True
        return False

    def reset(self):
        self.grid = torch.zeros([self.size, self.size], device=device)
        self.score = 0
        self.over = False
        self.addStartTile()

    def addStartTile(self):
        for i in range(2):
            self.addRandomTile()

    def addRandomTile(self):
        if self.cellsAvailable():
            value = 2 if randint(1, 10) < 10 else 4
            x, y = self.randomAvailableCell()
            self.grid[x, y] = value

    def availableCells(self):
        cells = []
        for i, j in [(i, j) for i in range(self.size) for j in range(self.size)]:
                if self.grid[i][j] == 0:
                    cells.append((i, j))
        return cells

    def cellsAvailable(self):
        return len(self.availableCells()) > 0

    def randomAvailableCell(self):
        cells = self.availableCells()
        if len(cells) > 0:
            return sample(cells, k=1)[0]

class DQN(nn.Module):
    def __init__(self):
        super(DQN, self).__init__()
        self.conv1 = nn.Conv2d(1, 2, (3, 3))
        self.line1 = nn.Linear(8, 4)

    def forward(self, x):
        x = x.unsqueeze(0).unsqueeze(0)
        x = self.conv1(x)
        x = self.line1(x.view(-1))
        x = F.softmax(x, dim=0)
        return x