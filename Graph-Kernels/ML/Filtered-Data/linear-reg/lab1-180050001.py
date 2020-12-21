import numpy as np
import matplotlib.pyplot as plt
from utils import load_data2, split_data, preprocess, normalize

np.random.seed(337)

def mse(X, Y, W):
	'''
	Compute mean squared error between predictions and true y values

	Args:
	X - numpy array of shape W = np.random.normal(0,1,(k(n_samples, n_features)
	Y - numpy array of shape (n_samples, 1)
	W - numpy array of shape (n_features, 1)
	'''

	## TODO
	Zc = np.dot(X,W) - Y
	# print(W.shape)
	n = X.shape[0]
	mse = (1/(2*n))*float(np.matmul(Zc.transpose(), Zc))
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.05, max_iter=2000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	k = X_train.shape[1]
	W = np.random.normal(0,1,(k,1))
	n = X_train.shape[0]
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train, Y_train, W)
		test_mse = mse(X_test, Y_test, W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		# print("ok")
		# print(W.shape)
		# print(X_train.shape)
		# print(Y_train.shape)
		W = W - (1/n)*lr*np.matmul(X_train.T, np.matmul(X_train,W)-Y_train)
		# print(W)
		## END TODO

	return W, train_mses, test_mses


def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.001, max_iter=500):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	k = X_train.shape[1]
	W = 0.001*np.random.normal(0,1,(k,1))
	n = X_train.shape[0]
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train, Y_train, W)
		test_mse = mse(X_test, Y_test, W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent		
		W = W - lr*(1/n)*np.dot(X_train.T, np.dot(X_train,W)-Y_train) - 2*lr*reg*W
		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	R = np.diag(r)
	X = np.matmul(R,X)
	Y = np.matmul(R,Y)
	W = np.matmul(np.matmul(np.linealg.inv(np.matmul(X.T, X)),X.T),Y)
	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)
	# print(Y_train.shape)

	W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	# W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)
	# print((W_ridge@W_ridge.T)[0][0])
	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()


