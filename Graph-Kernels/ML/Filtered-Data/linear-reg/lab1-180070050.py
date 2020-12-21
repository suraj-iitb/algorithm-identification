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

	N = X.shape[0]
	mse = 0.5*np.mean(((X @ W )- Y)**2)

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.001, max_iter=50000):
	train_mses = []
	test_mses = []

	N = len(X_train)
	D = X_train.shape[1]
	W = np.random.randn(D,1)
	#print(W.shape)
	#print(Y_train.shape)
#	print(X_train)
	# print(W)
	# print(Y_train)
	# print(np.matmul(X,W))
	for i in range(max_iter):

		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)

		train_mses.append(train_mse)
		test_mses.append(test_mse)
		grad_W = (X_train.T @ ((X_train @ W)-Y_train)) / N
		W -= lr*grad_W


	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.001, max_iter=800):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	N = len(X_train)
	D = X_train.shape[1]
	W = np.random.randn(D,1)
	## END TODO

	for i in range(max_iter):

		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)

		train_mses.append(train_mse)
		test_mses.append(test_mse)
		grad_W = (X_train.T @ ((X_train @ W)-Y_train)) / N
		grad_W += 2*reg*W
		W -= lr*grad_W


	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''
	r = r.reshape(-1,1)
	X = r*X
	Y = r*Y
	W = np.linalg.inv(X.T @ X) @ (X.T @ Y)

	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	# print(np.mean(X[:,7]))
	# print(np.std(X[:,7]))
	X_train, Y_train, X_test, Y_test = split_data(X, Y)
	#W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)
	print(len(train_mses))
	# Plots
	print(train_mses[-1])
	print(test_mses[-1])
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()