clear;
clc;
%%设飞行器相对雷达做匀加速直线运动
%%假设
total_time = 20;
interval_time = 2;%间隔时间
n=total_time / interval_time;%观测点数
%%初始化变量
x= [0 0.1]';
p_old = diag ([1 10]);
v = 0.15;
F=[1 2;
    0 1];
H =[1 0];
%%预测轨迹
x_pred = zeros(2, n+1);
x_pred(:, 1) = x;
%%观测轨迹
z = zeros (1, n);
z_temp = [0.36 1.56 3.64 6.44 10.5 14.8 20.0 25.2 32.2 40.4];
for i = 1: n
    z(i)=z_temp(i); %+ sqrt(v)* randn;
end
%%滤波轨迹初态
x_kalm = x_pred;
p_kalm = p_old;
%%预测过程
for i = 2 : n+1
    x_pred(:,i)=F * x_pred(:,i-1);
end
disp('预测状态');
disp(x_kalm);
%%滤波过程
for i = 2 : n+1
    x_pred(:,i)= F * x_kalm(:,i-1);
    p_pred = F * p_kalm * F';
    k = p_pred * H'/(H * p_pred * H'+v);
    x_kalm(:,i) = x_pred(:,i) + k * (z(:,i-1)-H * x_pred(:,i));
    p_kalm = (eye(2)-k * H) * p_pred;
end
disp('预测状态');
disp(x_pred);
disp('滤波状态');
disp(x_kalm);
disp('均方误差为：');
disp(p_kalm);

figure(1);
plot((1:n+1), x_kalm(1, :),'-oblack', (1:n+1), x_kalm(2, :),'-or')
title('可视化状态值');
xlabel('时间t/s');
%ylabe1('距离r/km');
legend('距离','速度');
hold on;

figure(2);
plot((1:n), z(1, : ),'+g', (1:n), x_pred(1,2:n+1),'xb', (1:n), x_kalm(1, 2:n+1),'or')
title('路程变化比较');
xlabel('时间t/s');
ylabel('距离r/(km)');
legend('量测轨迹','预测轨迹','滤波轨迹');
hold on;

figure(3);
plot ((1:n+1), x_pred(2,: ),'xb', (1:n+1), x_kalm(2, : ),'or')
title('速度变化比较');
xlabel('时间t/s')
ylabel('速度v/(km/s)');
legend('预测轨迹','滤波轨迹');
hold off;