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

	mse = (np.sum(np.square(np.matmul(X,W) - Y)))/(2*np.size(X,0))
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.00001, max_iter=2000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	#W = np.transpose([np.random.normal(size = np.size(X_train, 1))])
	W = np.zeros((np.size(X_train, 1), 1))
	
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train, Y_train, W)
		test_mse = mse(X_test, Y_test, W)


		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		'''for j in range(np.size(W, 0)):
			W[j, 0] = W[j, 0] - lr*(np.sum(((np.matmul(X_train,W) - Y_train)*X_train[:,j])))
		
			

		W = W/(np.size(X_train,0))'''
		Z = np.matmul(X_train,W) - Y_train
		W = W - lr*(np.matmul(np.transpose(X_train), Z))

		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.01, max_iter=2000):

	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	W = np.random.randn(np.size(X_train, 1), 1)/np.size(X_train, 0)

	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
	
		train_mse = mse(X_train, Y_train, W)
		print(train_mse)
		test_mse = mse(X_test, Y_test, W) 
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		Z = np.matmul(X_train,W) - Y_train
		W = W - lr*((np.matmul(np.transpose(X_train), Z)/(np.size(X_train, 0))) + (2*reg*W))
		T = np.matmul(W, np.transpose(W))
		print(T[0][0])

		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	n = X.shape[0]
	p = X.shape[1]
	r2 = np.square(np.diag(r))
	X = np.append(X, np.ones([n,1]), axis=1)
	XT = np.transpose(X)
	W = np.linalg.inv(XT @ r2 @ X) @ XT @ r2 @ Y
	




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

