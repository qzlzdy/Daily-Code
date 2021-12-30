import torch
import torch.nn as nn
import torch.nn.functional as F
from random import randint, shuffle

# device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
device = torch.device('cpu')

class Card21:
    def __init__(self):
        self.hand_cards = None
        self.pool = None
        self.index = None
        self.done = None
        self.reset()

    def reset(self):
        self.hand_cards = 0
        self.pool = [i + 1 for i in range(13)] * 4
        shuffle(self.pool)
        self.index = 0
        self.done = False

    def getScore(self):
        return self.hand_cards

    # action: True for take, False for not
    def step(self, action):
        if self.done:
            return 0, True
        if action:
            self.hand_cards += self.pool[self.index]
            self.index += 1
            if self.hand_cards > 21:
                self.done = True
        else:
            self.done = True
        if not self.done:
            return self.hand_cards, self.done
        reward = self.hand_cards
        if reward > 21:
            reward = -63
        elif reward <= 8:
            reward = -63
        return reward, self.done

    def getState(self):
        return torch.tensor(
            [self.hand_cards, self.pool[self.index]],
            device=device,
            dtype=torch.float)

class DQN(nn.Module):
    def __init__(self):
        super(DQN, self).__init__()
        self.lay1 = nn.Linear(2, 4, device=device)
        self.lay2 = nn.Linear(4, 1, device=device)

    def forward(self, x):
        x = x.to(device)
        x = self.lay1(x)
        x = self.lay2(x)
        x = F.sigmoid(x)
        return x >= 0.5
