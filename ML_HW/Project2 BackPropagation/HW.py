import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns


def sigmoid(x):
    if x >= 0:
        return 1.0 / (1 + np.exp(-x))
    else:
        return np.exp(x) / (1 + np.exp(x))


def sigmoid_(x):
    return sigmoid(x) * (1.0 - sigmoid(x))


class NN(object):
    def __init__(self, alpha=0.01, epoch=10000):
        self.w1_ = np.zeros(4)
        self.w2_ = 0
        self.b1 = 0
        self.b2 = 0
        self.alpha, self.epoch = alpha, epoch
        self.cost_ = []

    def calc_cost(self, Y, y):
        m = len(Y)
        j = Y @ np.log2(y) + (1 - Y) @ np.log2(1 - y)
        self.cost_.append(j/-m)

    def forward(self, X):
        z1 = self.w1_ @ X + self.b1
        a1 = sigmoid(z1)
        z2 = self.w2_ * a1 + self.b2
        a2 = sigmoid(z2)
        return z1, a1, z2, a2

    def backward(self, X, Y):
        z1, a1, z2, a2 = self.forward(X)
        dw1 = -(Y/(np.log(2) * a2) - (1-Y)/(np.log(2) * (1-a2))) * sigmoid_(z2) * self.w2_ * sigmoid_(z1) * X
        dw2 = -(Y/(np.log(2) * a2) - (1-Y)/(np.log(2) * (1-a2))) * sigmoid(z2) * a1
        db1 = -(Y/(np.log(2) * a2) - (1-Y)/(np.log(2) * (1-a2))) * sigmoid_(z2) * self.w2_ * sigmoid_(z1)
        db2 = -(Y/(np.log(2) * a2) - (1-Y)/(np.log(2) * (1-a2))) * sigmoid_(z2)
        return dw1, dw2, db1, db2

    def fit(self, X, Y):
        for _ in range(self.epoch):
            sumw1, sumw2, sumb1, sumb2 = np.zeros(4), 0, 0, 0
            for i in range(len(X)):
                dw1, dw2, db1, db2 = self.backward(X[i], Y[i])
                sumw1 += dw1
                sumw2 += dw2
                sumb1 += db1
                sumb2 += db2
            self.w1_ -= self.alpha * sumw1
            self.w2_ -= self.alpha * sumw2
            self.b1 -= self.alpha * sumb1
            self.b2 -= self.alpha * sumb2
            theta = np.zeros(len(Y))
            for i in range(len(Y)):
                theta[i] = sigmoid(self.w2_*sigmoid(self.w1_ @ X[i] + self.b1)+self.b2)
            self.calc_cost(Y, theta)

    def test(self, X, Y):
        correct = 0
        for i in range(len(Y)):
            yhat = sigmoid(self.w2_*sigmoid(self.w1_ @ X[i] + self.b1)+self.b2)
            if yhat >= 0.5:
                correct += 1
        return correct/len(Y)


X = np.loadtxt("iris.csv", delimiter=",", dtype=float, usecols=(1, 2, 3, 4))
dfy = np.loadtxt("iris.csv", delimiter=",", dtype=str, usecols=5)
Y = np.zeros(len(dfy))
for _ in range(len(dfy)):
    if dfy[_] == 'setosa':
        Y[_] = 1
    else:
        Y[_] = 0

train_x = X[:70]
train_y = Y[:70]
test_x = X[70:]
test_y = Y[70:]
nn = NN()
nn.fit(train_x, train_y)
sns.reset_orig()
plt.xlabel("epoch")
plt.ylabel("cost")
plt.plot(range(0, nn.epoch), nn.cost_)
plt.show()
print(nn.test(test_x, test_y))