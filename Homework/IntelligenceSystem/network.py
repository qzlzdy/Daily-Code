import torch
from torch import nn

class FireModule(nn.Module):
    def __init__(self, in_channels, out_channels, s1x1, e1x1, e3x3):
        super(FireModule, self).__init__()
        squeeze_1x1 = []
        inch = in_channels
        outch = in_channels
        for i in range(s1x1):
            squeeze_1x1.append(nn.Conv2d(inch, inch, (1, 1)))
        self.squeeze_1x1 = nn.Sequential(*squeeze_1x1)
        self.squeeze_relu = nn.ReLU()
        expand_1x1 = []
        for i in range(e1x1):
            expand_1x1.append(nn.Conv2d(inch, inch, (1, 1)))
        self.expand_1x1 = nn.Sequential(*expand_1x1)
        expand_3x3 = []
        for i in range(e3x3):
            if i + 1 == e3x3:
                outch = out_channels
            expand_3x3.append(nn.Conv2d(inch, outch, (3, 3), padding=1))
        self.expand_3x3 = nn.Sequential(*expand_3x3)
        self.expand_relu = nn.ReLU()

    def forward(self, x):
        x = self.squeeze_1x1(x)
        x = self.squeeze_relu(x)
        x = self.expand_1x1(x)
        x = self.expand_3x3(x)
        x = self.expand_relu(x)
        return x

class Network(nn.Module):
    def __init__(self):
        super(Network, self).__init__()
        self.conv1 = nn.Conv2d(1, 16, (7, 7), 2, 2)
        self.maxpool1 = nn.MaxPool2d((3, 3), 2)
        self.fire2 = FireModule(16, 32, 1, 6, 2)
        self.fire3 = FireModule(32, 32, 1, 6, 2)
        self.fire4 = FireModule(32, 48, 2, 12, 4)
        self.maxpool4 = nn.MaxPool2d((3, 3), 2)
        self.fire5 = FireModule(48, 48, 4, 24, 8)
        self.dropout = nn.Dropout2d()
        self.conv6 = nn.Conv2d(48, 64, (1, 1))
        self.avgpool6 = nn.AvgPool2d((15, 15), 1)
        self.flatten = nn.Flatten()
        self.hair_output = nn.Sequential(
            nn.Linear(64, 2),
            nn.Softmax(1)
        )
        self.hair_color_output = nn.Sequential(
            nn.Linear(64, 5),
            nn.Softmax(1)
        )
        self.gender_output = nn.Sequential(
            nn.Linear(64, 2),
            nn.Softmax(1)
        )
        self.earring_output = nn.Sequential(
            nn.Linear(64, 2),
            nn.Softmax(1)
        )
        self.smile_output = nn.Sequential(
            nn.Linear(64, 2),
            nn.Softmax(1)
        )
        self.frontal_face_output = nn.Sequential(
            nn.Linear(64, 2),
            nn.Softmax(1)
        )
        self.style_output = nn.Sequential(
            nn.Linear(64, 3),
            nn.Softmax(1)
        )

    def forward(self, x):
        x = self.conv1(x)
        x = self.maxpool1(x)
        bypass = self.fire2(x)
        x = self.fire3(bypass)
        x = self.fire4(x + bypass)
        x = self.maxpool4(x)
        x = self.fire5(x)
        x = self.dropout(x)
        x = self.conv6(x)
        x = self.avgpool6(x)
        x = self.flatten(x)
        hair = self.hair_output(x)
        hair_color = self.hair_color_output(x)
        gender = self.gender_output(x)
        earring = self.earring_output(x)
        smile = self.smile_output(x)
        frontal_face = self.frontal_face_output(x)
        style = self.style_output(x)
        return torch.cat((hair, hair_color, gender, earring, smile,
                          frontal_face, style), 1)
