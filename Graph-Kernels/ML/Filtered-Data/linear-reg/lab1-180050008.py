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
	y_hat = np.matmul(X,W)
	mse = sum((Y-y_hat)**2)/Y.shape[0]
	## END TODO

	return mse/2

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.01, max_iter=5000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	n,d = X_train.shape
	W = np.random.normal(0,1,(d,1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		# print("Ani1")
		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)
		# print("Ani2")
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		Y_pred = np.matmul(X_train,W)
		D_w = (-1/n) * np.dot(X_train.T,Y_train - Y_pred) 
		W = W-lr*D_w

		# print(D_w,"Ani")
        # D_b = (-1/n) * sum(Y_train - Y_pred)
		# 
		## END TODO

	# print(train_mses[-1])
	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.0001, max_iter=5000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	n,d = X_train.shape
	W = np.random.normal(0,1,(d,1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		# print("Ani1")
		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)
		# print("Ani2")
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		Y_pred = np.matmul(X_train,W)
		# print("Ani")
		D_w = (-1/n) * np.dot(X_train.T,Y_train - Y_pred) 

		# print(D_w,"Ani")
        # D_b = (-1/n) * sum(Y_train - Y_pred)
		# 
		W = (1-2*reg*lr)*W-lr*D_w
		## END TODO

	# print(train_mses[-1])
	# print(test_mses[-1])
	# print((W@W.T)[0][0])
	# print()
	# return W, train_mses, test_mses

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	R = np.diag(r)
	X = R@X
	Y = R@Y

	W = np.linalg.inv(X.T @ X) @ (X.T @ Y)
	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)

	W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)

	# W_wigthed = weighted_regression(X_train,Y_train,)

	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()

