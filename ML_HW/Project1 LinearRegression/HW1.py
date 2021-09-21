import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

'''
programming on Sept.21/2021
'''


class LinerRegression(object):
    def __init__(self, _alpha=0.001, _cnt=50):
        self.alpha = _alpha
        self.cnt = _cnt
        self.cost_ = []
        self.b = 0
        self.k = 0

    def calc_error(self, X, Y):
        error = 0
        for i in range(len(X)):
            error += (Y[i] - (self.k * X[i] + self.b)) ** 2
        self.cost_.append(error / len(X) / 2 + self.k ** 2 + self.b ** 2)
        return error / len(X) / 2 + self.k ** 2 + self.b ** 2

    def gradient_descent(self, X, Y):
        m = float(len(X))
        for i in range(self.cnt):
            b_temp = 0
            k_temp = 0
            for j in range(len(X)):
                b_temp += (self.k * X[i] + self.b) - Y[i]
                k_temp += ((self.k * X[i] + self.b) - Y[i]) * X[i]
            self.k -= self.alpha * (k_temp / m + 2 * self.k)
            self.b -= self.alpha * (b_temp / m + 2 * self.b)
            self.calc_error(X, Y)

    def show_regression(self, X, Y):
        self.gradient_descent(X, Y)
        print(self.b, self.k)
        plt.plot(X, Y, 'b.')
        plt.plot(X, self.k * X + self.b, 'r')
        plt.xlabel('X')
        plt.ylabel('Y')
        plt.show()

    def show_loss(self):
        sns.reset_orig()
        plt.plot(range(1, self.cnt + 1), self.cost_)
        plt.ylabel('cost')
        plt.xlabel('cnt')
        plt.show()


df = np.loadtxt('housing(1).csv', dtype=float, usecols=(2, 13))
train_x = np.array(df[0:400, 0:1])
train_y = np.array(df[0:400, 1:2])
train_x = train_x.flatten()
train_y = train_y.flatten()
print('Input alpha and cnt')
alpha = float(input())
cnt = int(input())
lr = LinerRegression(alpha, cnt)
lr.show_regression(train_x, train_y)
lr.show_loss()
