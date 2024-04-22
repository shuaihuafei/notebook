import cv2
import numpy as np
# 定义鼠标交互函数
def mouseColor(event, x, y, flags, param):
    # CV_EVENT_LBUTTONDOWN    =1,   //按下左键
    if event == cv2.EVENT_LBUTTONDOWN:
        print('HSV:', hsv[y, x])  #输出图像坐标(x,y)处的HSV的值
if __name__ == "__main__":
    cap = cv2.VideoCapture(15)
    cap.set(cv2.CAP_PROP_FRAME_WIDTH,600)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT,400)
    # img = cv2.imread('C:/Users/wenhaofu/Desktop/picture/on.png')  #读进来是BGR格式
    # C:/Users/wenhaofu/Desktop/picture/blue.png
    # C:/Users/wenhaofu/Desktop/picture/on.png
    while True:
        # 读取摄像头画面
        ret, img = cap.read()
        # 如果成功读取到画面
        if ret:
            hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)  #变成HSV格式
            cv2.namedWindow("Color Picker")
            '''
            winname:窗口的名字
            onMouse:鼠标响应函数，回调函数。指定窗口里每次鼠标时间发生的时候，被调用的函数指针。 
            这个函数的原型应该为void on_Mouse(int event, int x, int y, int flags, void* param);
            userdate：传给回调函数的参数 
            '''
            cv2.setMouseCallback("Color Picker", mouseColor) #鼠标相应回调函数
            cv2.imshow("Color Picker", img)

            
            low_hsv = np.array([75, 15, 221])
            high_hsv = np.array([95, 90, 255])
            mask = cv2.inRange(hsv, lowerb=low_hsv, upperb=high_hsv)
            cv2.imshow("test", mask)
        if cv2.waitKey(1) == 27:
            break
    # 释放摄像头资源和关闭窗口
    cap.release()
    cv2.destroyAllWindows()
