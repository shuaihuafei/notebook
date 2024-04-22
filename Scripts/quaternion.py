from scipy.spatial.transform import Rotation
import numpy as np

# 输入旋转矩阵
rotation_matrix = np.array([[0.1326360695236651, 0.9178149284147514, 0.3741970473431578],
                            [0.9523380353695432, -0.01337671926409867, -0.3047512588492582],
                            [-0.2746997259732735, 0.3967830900640217, -0.8758443012256544]])

# 创建Rotation对象并转换为四元数
rotation = Rotation.from_matrix(rotation_matrix)
quaternion = rotation.as_quat()

print("旋转矩阵:")
print(rotation_matrix)
print("对应的四元数:", quaternion)
