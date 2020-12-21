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
	predictions = np.matmul(X,W)
	true = Y
	diff = (predictions - true)
	diff = np.square(diff)
	mse = np.sum(diff)/(2*X.shape[0])
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.05, max_iter=2000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	W = np.random.normal(size=(X_train.shape[1] , 1) )
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train , Y_train, W)
		test_mse = mse(X_test , Y_test, W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		predictions = np.matmul(X_train, W)
		W = W - (lr/(X_train.shape[0]))*( np.matmul( np.transpose(X_train) , (predictions - Y_train) ) )
		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.01, max_iter=2000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	W = np.random.normal(size=(X_train.shape[1] , 1) )
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train , Y_train, W) 
		test_mse = mse(X_test , Y_test, W) 
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		predictions = np.matmul(X_train, W)
		W = W - lr*( np.matmul( np.transpose(X_train) , (predictions - Y_train) )/(X_train.shape[0]) + 2*reg*W)
		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''
	# print(r.shape)
	## TODO
	R = np.zeros([X.shape[0] , X.shape[0]])
	for i in range(X.shape[0]):
		R[i][i] = r[i]*r[i]
	# print(R)
	
	try:
		invr = np.linalg.inv( X.T @ R @ X) 
		W = invr @ ( (X.T @ R) @ Y)
	except np.linalg.LinAlgError:
		print("Singular Matrix error")
		return 

	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	
	# print(X[:20 , -1])
	X, Y = preprocess(X, Y)
	# print(X.shape , Y.shape)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)

	W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	# W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)
	# W_weigh = weighted_regression(X_train, Y_train, np.ones(X.shape[0]))
	# print(W_weigh , W)

	# print(train_mses[-1] , test_mses[-1])
	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()

