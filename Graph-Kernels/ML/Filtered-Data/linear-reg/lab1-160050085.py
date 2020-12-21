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
	mse = np.sum(((X@W - Y))**2, 0)/(2 * X.shape[0])
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.01, max_iter=20000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	w = np.random.normal(0, 1, (X_train.shape[1], 1))
	## END TODO

	for _ in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train, Y_train, w)
		test_mse = mse(X_test, Y_test, w)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		temp = (X_train@w - Y_train)/X_train.shape[0]
		w = w - lr * (X_train.T @ temp)
		## END TODO

	return w, train_mses, test_mses

def ridge_mse(X, Y, W, reg):
	temp = (X@W - Y)
	ridge_mse = (np.transpose(temp) @ temp)/(X.shape[0]) + reg * np.sum(W**2)
	# ridge_mse = np.sum(temp)/(2 * X.shape[0]) + reg * np.sum(W**2)

	return ridge_mse

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.001, max_iter=20000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	w = np.random.normal(0, 1, (X_train.shape[1], 1))
	## END TODO
	for _ in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train, Y_train, w)
		test_mse = mse(X_test, Y_test, w)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		temp = (X_train@w - Y_train) / X_train.shape[0]
		w = w - lr * ((X_train.T @ temp) + (2 * reg * w))
		## END TODO
	return w, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	print(np.diag(r))
	W = np.linalg.inv(np.transpose(X) @ np.diag(r) @ X) @ np.transpose(X) @ np.diag(r) @ Y
	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)

	W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	# W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)

	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()

