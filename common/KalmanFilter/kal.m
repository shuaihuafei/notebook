close all;
clear;
clc;
%% 这个文件是获得的雷达的测量数据
data = readtable('/home/shuai/mmw/LDR03/cpp/serial_socket/build/data_client.csv', 'VariableNamingRule', 'preserve');
n = height(data);
%%初始化变量
x = [345 0 0]';
p_old = diag([10 10 10]);
% 调参经验：Q中的位置噪声与R一起来看，如果位置噪声与观测噪声一样，则滤波结果就在预测结果和观测结果中间
%         Q中的速度噪声越大，则画出来的滤波曲线越不平滑，因为速度没有观测值，所以速度噪声越大，预测结果和滤波结果就会越向计算出来的速度值靠近，也就陡峭
%         Q中的加速度噪声越大，则画出来的滤波曲线越不平滑，并且加速度噪声会略微影响速度的滤波结果
Q = [0.1 0 0;
    0 10 0;
    0 0 100];
% 扩展到两个距离传感器，就写成
% R = [0.1 0 ;
%     0 0.1];
% 具体值看传感器精度
% 三个传感器同理
R = 0.1;
% 扩展到两个距离传感器，就写成
% H = [1 0 0;
%     1 0 0];
% 三个传感器同理
H = [1 0 0];

%%预测轨迹
x_pred = zeros(3, n + 1);
x_pred(:, 1) = x;

%%观测轨迹
z = data{:, 3}';
t = data{:, 2}';
v_real = data{:, 4}';
d_kalm_c = data{:, 6}';
v_kalm_c = data{:, 7}';

%%滤波轨迹初态
x_kalm = x_pred;
p_kalm = p_old;

%%滤波过程
for i = 2:n + 1
    t_ = t(:, i - 1);
    F = [1  t_  t_*t_/2;
        0   1   t_;
        0   0   1];
    x_pred(:, i) = F * x_kalm(:, i - 1);
    p_pred = F * p_kalm * F' + Q;
    k = p_pred * H' / (H * p_pred * H' + R);
    x_kalm(:, i) = x_pred(:, i) + k * (z(:, i - 1) - H * x_pred(:, i));
    p_kalm = (eye(3) - k * H) * p_pred;
end
disp('滤波状态');
disp(x_kalm);
disp('均方误差为：');
disp(p_kalm);

figure(1);
plot(1:n + 1, x_kalm(1, :), '-g', 1:n + 1, x_kalm(2, :), '-r', 1:n + 1, x_kalm(3, :), '-b')
title('可视化状态值');
xlabel('时间t/s');
legend('距离', '速度', '加速度');
hold on;

figure(2);
plot(1:n, z(1, :), '-g', 1:n, x_pred(1, 2:n + 1), '-b', 1:n, x_kalm(1, 2:n + 1), '-r', 1:n, d_kalm_c(1, :), '-m')
title('路程变化比较');
xlabel('时间t/s');
ylabel('距离r/(km)');
legend('量测轨迹1', '预测轨迹', '滤波轨迹_m', '滤波轨迹_c');
hold on;

figure(3);
plot(1:n, v_real(1, :), '-g', 1:n, x_pred(2, 2:n + 1), '-b', 1:n, x_kalm(2, 2:n + 1), '-r', 1:n, v_kalm_c(1, :), '-m')
title('速度变化比较');
xlabel('时间t/s')
ylabel('速度v/(km/s)');
legend('量测轨迹1', '预测轨迹', '滤波轨迹_m', '滤波轨迹_c');
hold on;

figure(4);
plot(1:n + 1, x_pred(3, :), '-b', 1:n + 1, x_kalm(3, :), '-r')
title('加速度变化比较');
xlabel('时间t/s');
ylabel('加速度a/(km/s^2)');
legend('预测轨迹', '滤波轨迹');
hold off;
