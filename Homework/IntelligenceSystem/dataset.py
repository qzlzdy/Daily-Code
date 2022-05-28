import torch
from torch.utils.data import Dataset
import torchvision
from torchvision.io import read_image, ImageReadMode

import json
import os

class SketchDataset(Dataset):
    def __init__(self, anno_file, img_dir, transform, target_transform):
        with open(anno_file, "rb") as f:
            self.img_labels = json.load(f)
        self.img_dir = img_dir
        self.transform = transform
        self.target_transform = target_transform

    def __len__(self):
        return len(self.img_labels)

    def __getitem__(self, idx):
        img_path = os.path.join(self.img_dir, self.__get_filename(idx))
        image = read_image(img_path, ImageReadMode.GRAY)
        one_hot = lambda y, l: (
            torch.zeros(l, dtype=torch.float)
                 .scatter_(dim=0, index=torch.tensor(y), value=1)
        )
        label = torch.cat((
            one_hot(self.img_labels[idx]["hair"], 2),
            one_hot(self.img_labels[idx]["hair_color"], 5),
            one_hot(self.img_labels[idx]["gender"], 2),
            one_hot(self.img_labels[idx]["earring"], 2),
            one_hot(self.img_labels[idx]["smile"], 2),
            one_hot(self.img_labels[idx]["frontal_face"], 2),
            one_hot(self.img_labels[idx]["style"], 3)
        ))
        if self.transform:
            image = self.transform(image)
        if self.target_transform:
            label = self.target_transform(label)
        return image, label

    def __get_filename(self, idx):
        image_name = self.img_labels[idx]["image_name"]
        dirname = os.path.dirname(image_name)
        basename = os.path.basename(image_name)
        filename = f"sketch{dirname[-1]}_sketch{basename[-4:]}.png"
        return filename
