import cv2
from PIL import Image
from anime_face_detector import create_detector

setuRoot = "/run/media/qzlzdy/Data/qzlzdy/setu"
datasetRoot = "/home/qzlzdy/python/datasets/setu"

def getPath(illust_id):
    extensions = [
        "jpg", "png", "bmp", "jpeg", "JPEG", "JPG"
    ]
    for ext in extensions:
        try:
            probe = Image.open(f"{setuRoot}/H{illust_id}.{ext}")
            return f"{setuRoot}/H{illust_id}.{ext}"
        except:
            pass
    raise "unknown extension"

detector = create_detector("yolov3", device="cpu")

def detect(fileid):
    image = cv2.imread(getPath(fileid))
    if image is None:
        raise "setu not found"
    preds = detector(image)
    count = 0
    width = len(image[0])
    height = len(image)
    for face in preds:
        (x0, y0, x1, y1, _) = face["bbox"]
        w = x1 - x0
        h = y1 - y0

        left = max(x0 - 0.25 * w, 0)
        right = min(x1 + 0.25 * w, width)
        top = max(y0 - 0.5 * h, 0)
        bottom = min(y1, height)

        center = ((left + right) / 2, (top + bottom) / 2)
        halfsize = min(right - left, bottom - top) / 2

        start_x = int(center[0] - halfsize)
        end_x = int(center[0] + halfsize)
        start_y = int(center[1] - halfsize)
        end_y = int(center[1] + halfsize)

        cropped = image[start_y:end_y, start_x:end_x]
        cv2.imwrite(f"{datasetRoot}/{fileid}-{count}.jpg", cropped)
        count += 1

l = [] + list(range(1440, 2000 + 1))

if __name__ == "__main__":
    for i in l:
        print(f"cropping illustration {i}")
        detect(i)
