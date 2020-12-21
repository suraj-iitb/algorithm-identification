import numpy as np
import matplotlib.pyplot as plt
import random
from utils import load_data2, split_data, preprocess, normalize, one_hot_encode

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
	error = np.subtract(np.dot(X,W), Y)
	mse_arr = np.dot(error.transpose(), error)
	mse = mse_arr[0][0]/(2*len(Y))
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.01, max_iter=2000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	features = len(X_train[0])
	W = np.zeros([features, 1])
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train, Y_train, W)
		test_mse = mse(X_test, Y_test, W)

		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		temp_arr = np.subtract(np.dot(X_train, W), Y_train)
		X_train = np.array(X_train)
		derivative = np.dot(X_train.transpose(), temp_arr)
		W = np.subtract(W, lr*derivative/len(Y_train))
		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.005, max_iter=2000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	features = len(X_train[0])
	W = np.zeros((features, 1))
	for i in range(features):
		W[i] = np.random.normal()
	## END TODO
	
	for i in range(max_iter):

		## TODO: Compute train and test MSE
		c = len(Y_train)
		c1 = len(Y_test)
		extra = reg*sum(W**2)
		train_mse = mse(X_train, Y_train, W) + (extra/(2*c))
		test_mse = mse(X_test, Y_test, W) + (extra/(2*c1))
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		temp_arr = np.dot(X_train, W) - Y_train
		X_train = np.array(X_train)
		derivative = np.dot(X_train.transpose(), temp_arr)
		#derivative = np.add(lr*derivative, reg*W)
		W = W - lr*((derivative/c) + (reg/c)*W) 
		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''
	## TODO
	term1 = np.dot(X.transpose(), r)
	term2 = np.dot(term1, X)
	term3 = np.dot(term1, Y)
	W = np.dot(np.linalg.inv(term2), term3)

	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)

	#W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)

	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()

