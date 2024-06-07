import cv2

# 打开笔记本摄像头
cap = cv2.VideoCapture(0)  # 奥比中光：5 是彩色图像
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 800)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 800)

while True:
    # w0 = cap.get(cv2.CAP_PROP_FRAME_WIDTH)
    # h0 = cap.get(cv2.CAP_PROP_FRAME_HEIGHT)
    # print("w0 is {}".format(w0))
    # print("h0 is {}".format(h0))
    # 读取摄像头画面
    ret, frame = cap.read()
    # 如果成功读取到画面
    if ret:
        # 左右镜像
        # frame = cv2.flip(frame, 1)
        # 显示画面
        cv2.imshow("Mirror Video", frame)
    # 检测键盘按键，如果按下ESC键，则退出循环
    if cv2.waitKey(1) == 27:
        break

# 释放摄像头资源和关闭窗口
cap.release()
cv2.destroyAllWindows()
