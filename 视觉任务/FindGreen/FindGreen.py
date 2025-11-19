import cv2
import numpy as np

img=cv2.imread("circle.png")
#=======读取数据=========
img_HSV=cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
#=======转换为HSV格式========
mark=np.zeros(img.shape,np.uint8)
GreenMin=np.array([50,50,50])
GreenMax=np.array([70,255,255])
mask=cv2.inRange(img_HSV,GreenMin,GreenMax)
roi=cv2.bitwise_and(img_HSV,img_HSV,mask=mask)
#=======获取含绿色的部分========
kernel=np.ones((7,7),np.uint8)
roi_1=cv2.morphologyEx(roi,cv2.MORPH_OPEN,kernel)
cv2.imshow("Green",roi_1)
cv2.waitKey(0)
#=======去噪点=========
gray=cv2.cvtColor(roi_1,cv2.COLOR_BGR2GRAY)
ret,binary=cv2.threshold(gray,127,255,cv2.THRESH_BINARY)
contours,hierarchy=cv2.findContours(binary,cv2.RETR_LIST,cv2.CHAIN_APPROX_SIMPLE)
#=======获取轮廓========
n=len(contours)
for i in range(n):
    x=cv2.moments(contours[i])['m10']
    y=cv2.moments(contours[i])['m01']
    print(f"区域{i+1}的坐标为({x:.1f},{y:.1f})")
#=======计算轮廓的重心坐标========
cv2.waitKey(0)
cv2.destroyAllWindows()