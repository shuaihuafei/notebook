clear;
clc;
%%设飞行器相对雷达做匀加速直线运动
%%假设
total_time = 20;
interval_time = 2;%间隔时间
n = total_time / interval_time; %观测点数

%%初始化变量
x = [0 0 0.3]';
p_old = diag([1 1 1]);
v = 0.15 * eye(2); % 两个传感器的噪声协方差矩阵
F = [1 2 2;
    0 1 2;
    0 0 1];
H = [1 0 0;
    1 0 0]; % 扩展到两个传感器

%%预测轨迹
x_pred = zeros(3, n + 1);
x_pred(:, 1) = x;

%%观测轨迹
z = zeros(2, n);
z_temp1 = [0.36 1.56 3.64 6.44 10.5 14.8 20.0 25.2 32.2 40.4];
z_temp2 = [0.35 1.55 3.65 6.40 10.45 14.75 20.05 25.15 32.25 40.45]; % 第二个传感器的测量值
for i = 1:n
    z(1, i) = z_temp1(i); %+ sqrt(v(1,1))* randn;
    z(2, i) = z_temp2(i); %+ sqrt(v(2,2))* randn;
end

%%滤波轨迹初态
x_kalm = x_pred;
p_kalm = p_old;

%%预测过程
for i = 2:n + 1
    x_pred(:, i) = F * x_pred(:, i - 1);
end
disp('预测状态');
disp(x_kalm);

%%滤波过程
for i = 2:n + 1
    x_pred(:, i) = F * x_kalm(:, i - 1);
    p_pred = F * p_kalm * F';
    k = p_pred * H' / (H * p_pred * H' + v);
    x_kalm(:, i) = x_pred(:, i) + k * (z(:, i - 1) - H * x_pred(:, i));
    p_kalm = (eye(3) - k * H) * p_pred;
end
disp('滤波状态');
disp(x_kalm);
disp('均方误差为：');
disp(p_kalm);

figure(1);
plot((1:n + 1), x_kalm(1, :), '-oblack', (1:n + 1), x_kalm(2, :), '-or', (1:n + 1), x_kalm(3, :), '-ob')
title('可视化状态值');
xlabel('时间t/s');
legend('距离', '速度', '加速度');
hold on;

figure(2);
plot((1:n), z(1, :), '+g', (1:n), z(2, :), '+g', (1:n), x_pred(1, 2:n + 1), 'xb', (1:n), x_kalm(1, 2:n + 1), 'or')
title('路程变化比较');
xlabel('时间t/s');
ylabel('距离r/(km)');
legend('量测轨迹1', '量测轨迹2', '预测轨迹', '滤波轨迹');
hold on;

figure(3);
plot((1:n + 1), x_pred(2, :), 'xb', (1:n + 1), x_kalm(2, :), 'or')
title('速度变化比较');
xlabel('时间t/s')
ylabel('速度v/(km/s)');
legend('预测轨迹', '滤波轨迹');
hold on;

figure(4);
plot((1:n + 1), x_pred(3, :), 'xb', (1:n + 1), x_kalm(3, :), 'or')
title('加速度变化比较');
xlabel('时间t/s');
ylabel('加速度a/(km/s^2)');
legend('预测轨迹', '滤波轨迹');
hold off;
