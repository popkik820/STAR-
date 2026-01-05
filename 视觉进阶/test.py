from ultralytics import YOLO
import cv2

# 加载模型
model = YOLO('yolov8n.pt')
#打开摄像头
cap = cv2.VideoCapture(0)
while True:
    ret, frame = cap.read()
    if not ret:
        break
    #获取结果
    results = model(frame, stream=True, conf=0.6)
    for result in results:
        boxes_xyxy = result.boxes.xyxy
        boxes_cls = result.boxes.cls
        for i, box in enumerate(boxes_xyxy):
            if boxes_cls[i] == 0: #判断识别对象是否为人
                x1, y1, x2, y2 = box[0],box[1],box[2],box[3]
                x1, y1, x2, y2 = int(x1), int(y1), int(x2), int(y2)
                #绘制矩形框和文本
                cv2.rectangle(frame, (x1, y1), (x2, y2), (0,255,0), 2)
                cv2.putText(frame,'Person', (x1, y1 - 10),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
    cv2.imshow('YOLO Detection', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
        cv2.caprelease
        cv2.destroyAllWindows()