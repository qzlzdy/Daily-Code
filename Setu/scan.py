from PIL import Image
import json
import sqlite3
import torch
from torchvision import transforms

db = sqlite3.connect('Setu.db')

model = torch.hub.load('~/Python/RF5_danbooru-pretrained_master', 'resnet50', source='local')
model.eval()

preprocess = transform.Compose([
    transforms.Resize(360),
    transforms.ToTensor(),
    transforms.Normalize(mean=[0.7137, 0.6628, 0.6519], std=[0.2970, 0.3017, 0.2979])
])

def tag(path):
    input_image = Image.open(path).convert('RGB')
    input_tensor = preprocess(input_image)
    input_batch = input_tensor.unsqueeze(0)

    with torch.no_grad():
        output = model(input_batch)

    probs = torch.sigmoid(output[0])
    tmp = probs[probs > 0.2]
    inds = probs.argsort(descending=True)
    try:
        for i in inds[0:len(tmp)]:
            db.execute(
                'INSERT INTO Setu (id, tag_id) VALUES (?, ?)',
                (path, i)
            )
    except:
        db.rollback()
    else:
        db.commit()

db.close()
