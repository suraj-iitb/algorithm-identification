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
	a = np.dot(X,W)-Y
	[c,d] = np.shape(X)
	a = np.square(a)
	mse = sum(a)/(2*c)
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.005, max_iter=10000):
	train_mses = []
	test_mses = []
	[c,d] = np.shape(X_train)
	## TODO: Initialize W using using random normal 
	W = np.random.normal(0.0, 1.0, (d,1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train, Y_train, W)
		test_mse = mse(X_test, Y_test, W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		a = np.dot(X_train,W)-Y_train
		a1 = np.transpose(X_train)
		a1 = np.dot(a1,a)
		W = W - lr*(a1/c)
		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.0001, max_iter=2000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []
	[c,d] = np.shape(X_train)
	[c1,d1] = np.shape(X_test)
	## TODO: Initialize W using using random normal 
	W = np.random.normal(0.0, 0.00005, (d,1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		ex = reg*sum(np.square(W))
		train_mse = mse(X_train, Y_train, W)+(ex/(2*c))
		test_mse = mse(X_test, Y_test, W)+(ex/(2*c1))
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		a = np.dot(X_train,W)-Y_train
		a1 = np.transpose(X_train)
		a1 = np.dot(a1,a)
		W = W - (lr*(a1/c) + 2*lr*(reg)*W)
		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	[c,d] = np.shape(X)
	nR = np.zeros([c,c])
	for i in range(c):
		nR[i,i] = r[i]*r[i]
	W = np.linalg.pinv((X.T @ nR) @ X) @ ((X.T @ nR) @ Y)
	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
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

