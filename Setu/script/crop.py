import cv2
import sys
import os.path
from PIL import Image

def getPath(illust_id):
    path = '/run/media/qzlzdy/Data/qzlzdy/setu/H{id}.{ext}'
    extensions = [
        'jpg', 'png', 'bmp', 'jpeg', 'JPEG'
    ]
    for ext in extensions:
        try:
            probe = Image.open(path.format(id=illust_id, ext=ext))
            return path.format(id=illust_id, ext=ext)
        except:
            pass
    return None

def detect(fileid, cascade_file = "./lbpcascade_animeface.xml"):
    cascade = cv2.CascadeClassifier(cascade_file)
    image = cv2.imread(getPath(fileid), cv2.IMREAD_COLOR)
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    gray = cv2.equalizeHist(gray)

    faces = cascade.detectMultiScale(gray,
                                     # detector options
                                     scaleFactor = 1.1,
                                     minNeighbors = 1,
                                     minSize = (192, 192))
    outname = '/home/qzlzdy/python/datasets/setu/{}-{}.jpg'
    i = 1
    for (x, y, w, h) in faces:
        width = len(image[0])
        height = len(image)
        start_x = max(int(x - 0.15 * w), 0)
        start_y = max(int(y - 0.4 * h), 0)
        end_x = min(int(start_x + 1.3 * w), width)
        end_y = min(int(start_y + 1.3 * h), height)
        edge_len = min(end_x - start_x, end_y - start_y)
        end_x = start_x + edge_len
        end_y = start_y + edge_len
        cropped = image[start_y: end_y, start_x: end_x]
        cv2.imwrite(outname.format(fileid, i), cropped)
        i += 1
        #cv2.rectangle(image, (x, y), (x + w, y + h), (0, 0, 255), 2)

l = [10524, 20650, 24267, 24661, 24907, 25038] + list(range(25225, 25556))
for i in l:
    print('cropping illustration', i)
    detect(i)
