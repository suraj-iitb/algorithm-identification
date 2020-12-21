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
	Y_prime = X@W
	mse = np.square(Y_prime-Y).mean()/2
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.045, max_iter=5000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	w = np.random.normal(size=[X_train.shape[1], 1])
	# print(w)
	# print(b)
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train, Y_train, w)
		test_mse = mse(X_test, Y_test, w)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		m = X_train.shape[0]
		w_grad = np.dot(X_train.T, np.dot(X_train, w)-Y_train)/m
		# print(w_grad)
		w = w - lr*w_grad
		# b = b - lr*b_grad

		if (i%100==0):
			print(i)
			print(train_mse)
		## END TODO

	return w, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.045, max_iter=3000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	w = np.random.normal(size=[X_train.shape[1], 1])
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train, Y_train, w)
		test_mse = mse(X_test, Y_test, w)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		m = X_train.shape[0]
		w_grad = (np.dot(X_train.T, np.dot(X_train, w)-Y_train)/m) + (reg/m)*w
		w = w - lr*w_grad

		if (i%100==0):
			print(i)
			print(train_mse)
		## END TODO

	return w, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	k = np.dot(np.dot(np.dot(X.T, r), r.T), X)
	k = np.linalg.inv(k)
	W = np.dot(k, X.T)
	W = np.dot(np.dot(np.dot(W, r), r.T), Y)
	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)

	# W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)

	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()

