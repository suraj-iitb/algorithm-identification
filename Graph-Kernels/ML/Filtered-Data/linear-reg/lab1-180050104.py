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
	si = X.shape[0]
	y_hat = np.dot(X,W)
	y_hat = np.reshape(y_hat,(y_hat.shape[0],1))
	err = Y - y_hat
	mse = err * err
	mse = np.sum(mse)/si
	mse = mse/2

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.01, max_iter=8000):
	train_mses = []
	test_mses = []

	W = np.random.normal(0, 0.3, (X_train.shape[1],1))

	for i in range(max_iter):
		si = X_train.shape[0]
		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)
		
		y_hat = np.dot(X_train,W)
		y_hat = np.reshape(y_hat,(y_hat.shape[0],1))
		W = W - (lr/si)*np.dot(X_train.T,(y_hat-Y_train))

		train_mses.append(train_mse)
		test_mses.append(test_mse)

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.001, max_iter=5000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	W = np.random.normal(0, 0.3, (X_train.shape[1],1))
	## END TODO

	for i in range(max_iter):

		si = X_train.shape[0]
		train_mse = mse(X_train,Y_train,W) +  (1/2)*(reg/si)*np.sum(W*W)
		test_mse = mse(X_test,Y_test,W) +  (1/2)*(reg/si)*np.sum(W*W)
		y_hat = np.dot(X_train,W)
		y_hat = np.reshape(y_hat,(y_hat.shape[0],1))
		W = W - ((lr/si)*np.dot(X_train.T,(y_hat-Y_train)) + (reg/si)*W)
		train_mses.append(train_mse)
		test_mses.append(test_mse)
	# print(train_mses[-1])
	# print(test_mses[-1])

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	R = np.diag(r*r)
	F = np.matmul(X.T,R)
	S = np.matmul(F,X)
	T = np.matmul(F,Y)
	A = np.linalg.inv(S)
	W = np.matmul(S,T)

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

