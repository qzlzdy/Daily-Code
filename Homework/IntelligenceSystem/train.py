from dataset import SketchDataset
from network import Network

import torch
from torch import nn
import torch.nn.functional as F
from torch.utils.data import DataLoader
import torchvision
from torchvision import transforms

batch_size = 512

def train_loop(dataloader, model, loss_fn, optimizer):
    size = len(dataloader.dataset)
    for batch, (X, y) in enumerate(dataloader):
        pred = model(X)
        loss = loss_fn(pred, y)
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
        #if batch % 10 == 0:
        loss, current = loss.item(), batch * len(X)
        print(f"loss: {loss:>7f} [{current:>5d}/{size:>5d}]")

def test_loop(dataloader, model, loss_fn):
    size = len(dataloader.dataset)
    num_batches = len(dataloader)
    test_loss = 0
    hair_correct = 0
    hair_color_correct = 0
    gender_correct = 0
    earring_correct = 0
    smile_correct = 0
    frontal_face_correct = 0
    style_correct = 0
    with torch.no_grad():
        for X, y in dataloader:
            pred = model(X)
            test_loss += loss_fn(pred, y).item()
            hair_correct += (pred[:, 0:2].argmax(1) == y[:, 0:2].argmax(1)).type(torch.float).sum().item()
            hair_color_correct += (pred[:, 2:7].argmax(1) == y[:, 2:7].argmax(1)).type(torch.float).sum().item()
            gender_correct += (pred[:, 7:9].argmax(1) == y[:, 7:9].argmax(1)).type(torch.float).sum().item()
            earring_correct += (pred[:, 9:11].argmax(1) == y[:, 9:11].argmax(1)).type(torch.float).sum().item()
            smile_correct += (pred[:, 11:13].argmax(1) == y[:, 11:13].argmax(1)).type(torch.float).sum().item()
            frontal_face_correct += (pred[:, 13:15].argmax(1) == y[:, 13:15].argmax(1)).type(torch.float).sum().item()
            style_correct += (pred[:, 15:18].argmax(1) == y[:, 15:18].argmax(1)).type(torch.float).sum().item()
    test_loss /= num_batches
    hair_correct /= size
    hair_color_correct /= size
    gender_correct /= size
    earring_correct /= size
    smile_correct /= size
    frontal_face_correct /= size
    style_correct /= size
    print(f"Test Error: ")
    print(f" Hair Accuracy: {(100 * hair_correct):>0.1f}%,")
    print(f" Hair Color Accuracy: {(100 * hair_color_correct):>0.1f}%,")
    print(f" Gender Accuracy: {(100 * gender_correct):>0.1f}%,")
    print(f" Earring Accuracy: {(100 * earring_correct):>0.1f}%,")
    print(f" Smile Accuracy: {(100 * smile_correct):>0.1f}%,")
    print(f" Frontal Face Accuracy: {(100 * frontal_face_correct):>0.1f}%,")
    print(f" Style Accuracy: {(100 * style_correct):>0.1f}%,")
    print(f" Avg loss: {test_loss:>8f}")

def cross_entropy(pred, y):
    loss = 0
    loss += F.cross_entropy(pred[:, 0:2], y[:, 0:2])
    loss += F.cross_entropy(pred[:, 2:7], y[:, 2:7])
    loss += F.cross_entropy(pred[:, 7:9], y[:, 7:9])
    loss += F.cross_entropy(pred[:, 9:11], y[:, 9:11])
    loss += F.cross_entropy(pred[:, 11:13], y[:, 11:13])
    loss += F.cross_entropy(pred[:, 13:15], y[:, 13:15])
    loss += F.cross_entropy(pred[:, 15:18], y[:, 15:18])
    return loss

def train():
    preprocess = transforms.Compose([
        transforms.CenterCrop(475),
        transforms.Resize(128),
        transforms.TrivialAugmentWide(fill=0),
        transforms.ConvertImageDtype(torch.float),
        transforms.Normalize([0], [255])
    ])
    trainning_data = SketchDataset("./anno_train.json", "./train/sketch", preprocess, None)
    test_data = SketchDataset("./anno_test.json", "./test/sketch", preprocess, None)
    train_dataloader = DataLoader(trainning_data, batch_size, True)
    test_dataloader = DataLoader(test_data, batch_size, True)

    model = Network()
    optimizer = torch.optim.NAdam(model.parameters(), 0.04)
    scheduler = torch.optim.lr_scheduler.StepLR(optimizer, 1, 0.9)

    epochs = 20
    for t in range(epochs):
        print(f"Epoch {t + 1}\n-------------------------------")
        train_loop(train_dataloader, model, cross_entropy, optimizer)
        test_loop(test_dataloader, model, cross_entropy)
        scheduler.step()
        if (t + 1) % 5 == 0:
            torch.save(model.state_dict(), f"./model_weights_{t + 1}.pth")
    #torch.save(model.state_dict(), f"./model_weights_{epochs}.pth")
    print("Done!")

if __name__ == "__main__":
    train()
