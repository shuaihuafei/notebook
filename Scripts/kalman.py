import numpy as np

# 初始化状态
x = np.array([[0], [0]])  # 初始状态
P = np.array([[1, 0], [0, 1]])  # 初始协方差矩阵

# 状态转移矩阵
F = np.array([[1, 0], [0, 1]])

# 测量矩阵
H = np.array([[1, 0], [0, 1]])

# 过程噪声协方差
Q = np.array([[0.1, 0], [0, 0.1]])

# 测量噪声协方差
R = np.array([[0.5, 0], [0, 0.5]])

# 控制输入矩阵和输入（如果没有控制输入，可以忽略）
B = np.array([[0], [0]])  # 确保B的维度为 (2, 1)
u = np.array([[0]])  # 确保u的维度为 (1, 1)

# 传感器数据（示例）
z1 = [1, 2, 3]  # 传感器1数据
z2 = [1.2, 1.9, 3.1]  # 传感器2数据

# 卡尔曼滤波迭代
for i in range(len(z1)):
    # 预测步骤
    x = np.dot(F, x) + np.dot(B, u)  # 确保np.dot(B, u)维度正确
    P = np.dot(np.dot(F, P), F.T) + Q

    # 测量值
    z = np.array([[z1[i]], [z2[i]]])

    # 更新步骤
    y = z - np.dot(H, x)
    S = np.dot(np.dot(H, P), H.T) + R
    K = np.dot(np.dot(P, H.T), np.linalg.inv(S))
    x = x + np.dot(K, y)
    P = P - np.dot(np.dot(K, H), P)

    # 输出当前状态
    print(f"时间 {i} 的估计状态: {x.flatten()}")
