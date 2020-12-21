import numpy as np
import matplotlib.pyplot as plt
from utils import load_data2, split_data, preprocess, normalize

np.random.seed(337)

def mse(X, Y, W):
	'''
	Compute mean squared error between predictions and true y values

	Args:
	X - numpy array of shape (n_samples, n_features)
	Y - numpy array of shape (n_samples, 1)
	W - numpy array of shape (n_features, 1)
	'''

	## TODO

	return 0.5 * np.mean((np.matmul(X, W) - Y)**2)

	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.01, max_iter=100000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 

	W = np.random.normal(size = (X_train.shape[1], 1))

	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE

		train_mse = mse(X_train, Y_train, W)
		test_mse = mse(X_test, Y_test, W)

		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent

		W = W - lr * np.matmul(X_train.T, np.matmul(X_train, W) - Y_train) / X_train.shape[0]

		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.01, max_iter=100000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 

	W = np.random.normal(size = (X_train.shape[1], 1))

	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE

		train_mse = mse(X_train, Y_train, W)
		test_mse = mse(X_test, Y_test, W)

		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent

		W = W - lr * (np.matmul(X_train.T, np.matmul(X_train, W) - Y_train)/X_train.shape[0] + 2*reg*W)

		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO

	r.shape = (r.shape[0], 1)
	X = r * X
	Y = r * Y

	W = np.matmul(np.linalg.inv(np.matmul(X.T, X)), np.matmul(X.T, Y))

	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data4.csv')
	X, Y = preprocess(X, Y)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)

	W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	#W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)

	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()
