import cv2
import numpy as np
import math

# 帅：这个阈值现场要调
low_bound, high_bound = (0, 0, 221), (180, 30, 255)
k_thres_ = 0.2

def preprocess(image,roi_heigh,roi_width,ros_height_delta):
    # 转换成hsv
    # image = cv2.convertScaleAbs(image,1.5,10)
    # roi_height_start = int(image.shape[0]/2-roi_heigh/2)-ros_height_delta
    # roi_height_end = int(image.shape[0]/2+roi_heigh/2)-ros_height_delta
    # roi_width_start = int(image.shape[1]/2-roi_width/2)
    # roi_width_end = int(image.shape[1]/2+roi_width/2)
    # image=image[roi_height_start:roi_height_end,
    #             roi_width_start:roi_width_end]
    hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    # 卡白色阈值(在阈值内部的为255, 不在的是0)
    mask = cv2.inRange(hsv, low_bound, high_bound)
    # 取反操作(0和255交换位置)，原本的白色变为黑色
    # mask = cv2.bitwise_not(mask)
    # 膨胀/腐蚀去除噪声
    kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (5, 5), (-1, -1))
    mask = cv2.dilate(mask, kernel, 2)
    mask = cv2.erode(mask, kernel, 2)
    return image, mask

def calculate_ratio(a, b):
    '''
    :param a: 角点1
    :param b: 角点2
    :return: 斜率
    '''
    if abs(b[0][0] - a[0][0]) < 1e-3:
        # 横坐标相等, 斜率无穷大
        if a[0][0] == 0 or a[0][0] == 1919:
            return 0
        else:
            return 999
    else:
        # 计算斜率
        return (b[0][1] - a[0][1]) / (b[0][0] - a[0][0])


def get_distance(a, b):
    '''
    :param a: 角点1
    :param b: 角点2
    :return: 两点距离
    '''
    distance = pow(a[0][0] - b[0][0], 2) + pow(a[0][1] - b[0][1], 2)
    return math.sqrt(distance)


def set_point(p_vector, p):
    '''
    :param p_vector: 关键点列表
    :param p: 角点
    :return:
    '''
    # 每个轮廓只保存两个点, 保存y坐标较小的
    if len(p_vector) < 2:
        p_vector.append(p[:])
    else:
        if p[1] > p_vector[0][1]:
            p_vector[0] = p[:]
        elif p[1] > p_vector[1][1]:
            p_vector[1] = p[:]


def get_pavement_corner_point(image, mask):
    '''
    :param mask: 斑马线的mask(白色斑马线为0, 其他为255)
    :return:
    '''
    # global image
    # 找轮廓：cv2.RETR_TREE就是之前我们一直在使用的方式，它会完整建立轮廓的层级从属关系
    contours, hierarchy = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_NONE)
    contours_poly = []
    up_corner = []
    count_contours = 0
    # 遍历轮廓坐标contours, hierarchy是各轮廓的层级关系数组
    for i, contour in enumerate(contours):
        # 用最小多边形去拟合轮廓, 并保存拟合多边形的角点
        contours_poly.append(cv2.approxPolyDP(contour, 5, True))
        if len(contours_poly[i]) < 4 or len(contours_poly[i]) > 7 or cv2.contourArea(contours_poly[i]) < 500:
            continue  # 筛掉奇怪边形
        count_contours+=1
        # 绘制第i个轮廓的拟合多边形角点(image是全局变量，所以会被不断修改，每次循环画一个多边形上去)
        # 帅：这里的image怎么处理？
        image = cv2.drawContours(image, contours_poly, i, (0, 0, 255), 1, 8)
        # cad_point = []
        # # 循环多边形的角点
        # for j in range(len(contours_poly[i])):
        #     # 算斜率找其中的关键点
        #     k = calculate_ratio(contours_poly[i][j], contours_poly[i][(j + 1) % len(contours_poly[i])])
        #     # 如果相邻两点斜率大于阈值 并且 距离超过10
        #     if abs(k) > k_thres_ and get_distance(contours_poly[i][j],
        #                                           contours_poly[i][(j + 1) % len(contours_poly[i])]) > 10:
        #         # 保存y坐标较小的角点即可
        #         # 帅：因为这里contours_poly[i][j]是一个二维数组，类似于[[21 56]]，所以需要再加一层检索，得到坐标
        #         if contours_poly[i][j][0][1] > contours_poly[i][(j + 1) % len(contours_poly[i])][0][1]:
        #             set_point(cad_point, contours_poly[i][j][0])
        #         else:
        #             set_point(cad_point, contours_poly[i][(j + 1) % len(contours_poly[i])][0])
        #     else:
        #         # print('k:', k)
        #         pass
        # if len(cad_point) == 2:
        #     up_corner.append(cad_point[0])
        #     up_corner.append(cad_point[1])
        #     # 画出关键点
        #     cv2.circle(image, tuple(cad_point[0]), 3, (255, 255, 0), 3)
        #     cv2.circle(image, tuple(cad_point[1]), 3, (255, 255, 0), 3)
    # # 求出所有up_corner中y坐标的平均值
    # y_coordinates = [coord[1] for coord in up_corner]
    # average_y = np.mean(y_coordinates)
    return count_contours, image

def stop_car(count_contours):
    if(count_contours >= 2):
        return 1
    return 0

if __name__ == "__main__":
    # 打开笔记本摄像头
    cap = cv2.VideoCapture(0)
    cap.set(cv2.CAP_PROP_FRAME_WIDTH,800)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT,600)

    while True:
        # 读取摄像头画面
        ret, image = cap.read()
        # 如果成功读取到画面
        if ret:
            roi_heigh = 640
            roi_width = 360
            ros_height_delta = 0
            image, mask = preprocess(image,roi_heigh,roi_width,ros_height_delta)
            cv2.imshow("mask",mask)
            count_contours, image = get_pavement_corner_point(image, mask)
            cv2.imshow("image",image)
            # print(up_corner_y)
            # print(average_yy)

        # 检测键盘按键，如果按下ESC键，则退出循环
        if cv2.waitKey(1) == 27:
            break

    # 释放摄像头资源和关闭窗口
    cap.release()
    cv2.destroyAllWindows()