from dataset import SketchDataset
from network import Network

import torch
from torch.utils.data import DataLoader
import torchvision
from torchvision import transforms

tp = [
    [0, 0],     # hair
    [0, 0, 0, 0, 0],    # hair color
    [0, 0],     # gender
    [0, 0],     # earring
    [0, 0],     # smile
    [0, 0],     # frontal face
    [0, 0, 0]   # style
]

fp = [
    [0, 0],     # hair
    [0, 0, 0, 0, 0],    # hair color
    [0, 0],     # gender
    [0, 0],     # earring
    [0, 0],     # smile
    [0, 0],     # frontal face
    [0, 0, 0]   # style
]

ap = [
    [0, 0, 0],     # hair
    [0, 0, 0, 0, 0, 0],    # hair color
    [0, 0, 0],     # gender
    [0, 0, 0],     # earring
    [0, 0, 0],     # smile
    [0, 0, 0],     # frontal face
    [0, 0, 0, 0]   # style
]

cname = [
    "Hair",
    "Hair Color",
    "Gender",
    "Earring",
    "Smile",
    "Frontal Face",
    "Style"
]

def calculate_ap(pred, real, c):
    l = len(tp[c])
    for i in range(l):
        if pred == i:
            if pred == real:
                tp[c][i] += 1
                ap[c][i] += tp[c][i] / (tp[c][i] + fp[c][i])
            else:
                fp[c][i] += 1

def main():
    model = Network()
    model.load_state_dict(torch.load("./model_weights_20.pth"))
    model.eval()

    preprocess = transforms.Compose([
        transforms.CenterCrop(475),
        transforms.Resize(128),
        transforms.ConvertImageDtype(torch.float),
        transforms.Normalize([0], [255])
    ])
    test_data = SketchDataset("./anno_test.json", "./test/sketch", preprocess, None)
    test_dataloader = DataLoader(test_data)

    size = len(test_dataloader.dataset)
    for current, (X, y) in enumerate(test_dataloader):
        pred = model(X).squeeze(0)
        pred_res = [
            pred[0:2].argmax(),
            pred[2:7].argmax(),
            pred[7:9].argmax(),
            pred[9:11].argmax(),
            pred[11:13].argmax(),
            pred[13:15].argmax(),
            pred[15:18].argmax(),
        ]
        y = y.squeeze(0)
        real_res = [
            y[0:2].argmax(),
            y[2:7].argmax(),
            y[7:9].argmax(),
            y[9:11].argmax(),
            y[11:13].argmax(),
            y[13:15].argmax(),
            y[15:18].argmax(),
        ]
        for c in range(7):
            calculate_ap(pred_res[c], real_res[c], c)
        if current % 200 == 0:
            print(f"process [{current:>5d}/{size:>5d}]")
    for c in range(7):
        print(f"Average Precision for {cname[c]}: ")
        l = len(tp[c])
        for i in range(l):
            if tp[c][i] != 0:
                ap[c][i] /= tp[c][i]
            print(f" Class {i}: {(100 * ap[c][i]):>0.1f}%,")
            ap[c][-1] += ap[c][i]
        ap[c][-1] /= l
        print(f" Mean Average Precision: {(100 * ap[c][-1]):>0.1f}%")
        print()

if __name__ == "__main__":
    main()
