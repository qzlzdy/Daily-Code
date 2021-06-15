from PIL import Image
import json
import sqlite3
import torch
from torchvision import transforms

db = sqlite3.connect('../Setu.db')

model = torch.hub.load('/home/qzlzdy/Python/RF5_danbooru-pretrained', 'resnet50', source='local')
model.eval()

preprocess = transforms.Compose([
    transforms.Resize(360),
    transforms.ToTensor(),
    transforms.Normalize(mean=[0.7137, 0.6628, 0.6519], std=[0.2970, 0.3017, 0.2979])
])

def getPath(illust_id):
    path = '/run/media/qzlzdy/Data/qzlzdy/setu/H{id}.{ext}'
    cur = db.execute('SELECT extension FROM Illustrations WHERE id = ?', (illust_id,))
    return path.format(id=illust_id, ext=cur.fetchone()[0])

def captioning(illust_id):
    input_image = Image.open(getPath(illust_id)).convert('RGB')
    input_tensor = preprocess(input_image)
    input_batch = input_tensor.unsqueeze(0)

    with torch.no_grad():
        output = model(input_batch)

    probs = torch.sigmoid(output[0])
    tmp = probs[probs >= 0.2]
    inds = probs.argsort(descending=True)
    for i in inds[0:len(tmp)]:
        db.execute(
            'INSERT INTO have (illust_id, cate_id) VALUES (?, ?)',
            (int(illust_id), int(i))
        )
    db.commit()
        
for i in range(101, 201):
    print('captioning illustration', i)
    captioning(i)

db.close()
