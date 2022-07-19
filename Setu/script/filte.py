import cv2
import os

datasetRoot = "/home/qzlzdy/Datasets/setu"

setus = os.listdir(datasetRoot)
total = len(setus)
count = 0

for path in setus:
    image = cv2.imread(f"{datasetRoot}/{path}")
    if len(image) < 230:
        os.remove(f"{datasetRoot}/{path}")
    count += 1
    if count % 100 == 0:
        print(f"process [{count} / {total}]")
