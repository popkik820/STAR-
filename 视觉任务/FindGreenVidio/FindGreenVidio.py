import cv2
import numpy as np

cap=cv2.VideoCapture("Woods.mp4")
while(cap.isOpened()):
    ret,frame=cap.read()
    img_HSV=cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
    mask=np.zeros(frame.shape,np.uint8)
    GreenMin = np.array([30, 50, 50])
    GreenMax = np.array([85, 255, 255])
    mask = cv2.inRange(img_HSV, GreenMin, GreenMax)
    roi = cv2.bitwise_and(img_HSV, img_HSV, mask=mask)
    cv2.imshow("Green",roi)
    c=cv2.waitKey(10)
    if c==27:
        break
cap.release()
cv2.waitKey(0)
cv2.destroyAllWindows()