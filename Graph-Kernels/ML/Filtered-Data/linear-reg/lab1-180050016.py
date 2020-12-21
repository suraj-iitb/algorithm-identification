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
	n_samples = X.shape[0]

	mse = np.sum(np.square((X @ W) - Y)) / (2 * n_samples)
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.03, max_iter=3000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	N_train, D = X_train.shape
	W = np.random.randn(D,1)
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train, Y_train, W)
		test_mse = mse(X_test, Y_test, W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		s1 = (X_train @ W) - Y_train
		dW = (s1.T @ X_train) / N_train
		dW = dW.T
		W -= (lr * dW)
		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.002, max_iter=9000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	N_train, D = X_train.shape
	W = np.random.randn(D,1)
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train, Y_train, W)
		test_mse = mse(X_test, Y_test, W)

		# if(i%50 ==0 ):
		# 	print(i, train_mse)
		# 	print(i, test_mse)
		# 	print((W@W.T)[0][0] )
		# 	W_act = np.linalg.inv(X_train.T @ X_train + 2 * reg * X_train.shape[0] * np.eye(X_train.shape[1])) @ X_train.T @ Y_train
		# 	print(np.linalg.norm(W - W_act) )

		# 	print('\n')
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		s1 = (X_train @ W) - Y_train
		dW = (s1.T @ X_train) / N_train
		dW += 2*reg*W.T
		dW = dW.T
		W -= (lr * dW)
		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	# phi = np.matmul(r.T,X)
	# left = np.linalg.inv(np.matmul(phi.T, phi))
	# right = np.matmul(np.matmul(phi.T, r.T),Y)

	# W = np.matmul(left,right)
	R = np.diag(r)
	phi = R.T @ X
	Y_new = R.T @ Y

	left = np.linalg.inv(phi.T @ phi)
	right = phi.T @ Y_new

	W = left @ right
	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	# X, Y = load_data2('data2.csv')
	# X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)

	W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	# W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)
	#print(W)


	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()

