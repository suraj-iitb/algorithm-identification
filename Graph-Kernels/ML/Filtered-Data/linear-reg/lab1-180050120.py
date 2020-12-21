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
	sub = np.dot(X,W)-Y
	N = X.shape[0]
	norm = np.dot(sub.T,sub)
	mse = norm[0,0] / (2*N)
	## END TODO

	return mse

# def derivative_w(X,Y,W):
# 	mat = np.dot(X.T,(np.dot(X,W)-Y))
# 	N = X.shape[0]
# 	diff = (1/N) * mat 

# 	return diff

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.065, max_iter=2000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	n_features = X_train.shape[1]
	W = np.random.normal(size=(n_features,1))
	N = X_train.shape[0]
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test, Y_test, W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		der_W = (1/N) * np.dot(X_train.T,(np.dot(X_train,W)-Y_train))
		W = W - lr * der_W
		# print(type(W))
		# print(type(derivative_w(X_train,Y_train,W)))
		## END TODO
	# print("train: ", train_mse)
	# print("test: ", test_mse)
	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.001, max_iter=2000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	n_features = X_train.shape[1]
	W = np.random.normal(size=(n_features,1))
	N = X_train.shape[0]
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train, Y_train, W) 
		test_mse = mse(X_test, Y_test, W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)



		## TODO: Update w and b using a single step of gradient descent
		# print("test: ", test_mse)
    	# print("train: ", train_mse)


		der_W = (1/N) * np.dot(X_train.T,(np.dot(X_train,W)-Y_train))  
		W = W - lr * (der_W + 2 * reg * W) 
		## END TODO
	# print("train: ", train_mse)
	# print("test: ", test_mse)

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	R = np.diag(r * r)
	A = np.dot(X.T,np.dot(R,X))
	b = np.dot(X.T,np.dot(R,Y))
	W = np.dot(np.linalg.inv(A),b)

	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	# print(X.shape)
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

