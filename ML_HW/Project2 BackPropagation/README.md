# 第二次作业



使用单隐藏层的简单神经网络完成鸢尾花的二分类



## 模型



输入层 含有四个节点，分别对应为鸢尾花的特征向量 X ，维数为4维

隐藏层 含有一个节点

输出层 含有一个节点

其中采用的 `active function `为`sigmoid function`

则输出可描述为：$\hat y_i = \sigma(w_2\sigma(w_1X_i + b_1)+b_2)$

定义此神经网络的 `Loss` 函数为交叉熵函数，即：$Loss(w, b) = -\frac{1}{n}\sum^n_{i=1}[y_i\log_2{\hat y_i} + (1-y_i)\log_2({1-\hat y_i})]$



## 过程

1. 前向传播：

   ​	有如下赋值：
   $$
   z_1 = w_1X_i + b_1\\
   a_1 = \sigma(z_1)\\
   z_2 = w_2a_1 + b_2\\
   a_2 = \sigma(z2)
   $$
   显然有   $\hat y_i = a_2$

   通过对输入的特征向量 $X_i$ 进行前向传导，计算出其对应的输出 $\hat y_i$，及隐藏层的值，为反向传导做数值计算

2. 反向传播

   ​	对$J = Loss(w,b)$求偏导，有如下式子：
   $$
   \frac{\partial J}{\partial w_1} = \frac{\partial J}{\partial a_2}\frac{\partial a_2}{\partial z_2}\frac{\partial z_2}{\partial a_1}\frac{\partial a_1}{\partial z_1}\frac{\partial z_1}{\partial w_1}\\
   \frac{\partial J}{\partial w_2} = \frac{\partial J}{\partial a_2}\frac{\partial a_2}{\partial z_2}\frac{\partial z_2}{\partial w_2}\\
   \frac{\partial J}{\partial b_1} = \frac{\partial J}{\partial a_2}\frac{\partial a_2}{\partial z_2}\frac{\partial z_2}{\partial a_1}\frac{\partial a_1}{\partial z_1}\frac{\partial z_1}{\partial b_1}\\
   \frac{\partial J}{\partial b_2} = \frac{\partial J}{\partial a_2}\frac{\partial a_2}{\partial z_2}\frac{\partial z_2}{\partial b_2}\\
   $$
   即：
   $$
   \frac{\partial J}{\partial w_1} = -\frac{1}{n}\sum^n_{i=1}[(\frac{y_i}{\ln2 \hat y_i} - \frac{1-y_i}{\ln2 (1-\hat y_i)})\sigma'(z_2)w_2\sigma'(z_1)X_i]\\
   \frac{\partial J}{\partial w_2} = -\frac{1}{n}\sum^n_{i=1}[(\frac{y_i}{\ln2 \hat y_i} - \frac{1-y_i}{\ln2 (1-\hat y_i)})\sigma'(z_2)a_1]\\
   \frac{\partial J}{\partial b_1} = -\frac{1}{n}\sum^n_{i=1}[(\frac{y_i}{\ln2 \hat y_i} - \frac{1-y_i}{\ln2 (1-\hat y_i)})\sigma'(z_2)w_2\sigma'(z_1)]\\
   \frac{\partial J}{\partial b_2} =  -\frac{1}{n}\sum^n_{i=1}[(\frac{y_i}{\ln2 \hat y_i} - \frac{1-y_i}{\ln2 (1-\hat y_i)})\sigma'(z_2)]
   $$

调整学习率与迭代次数，得到`Loss - epoch`的图像

并在测试集上计算网络分类的正确率

## 总结

发现在$\alpha = 0.05, epoch = 10^4$时，`Loss`函数下降趋于稳定，正确率也稳定在`0.533333`左右