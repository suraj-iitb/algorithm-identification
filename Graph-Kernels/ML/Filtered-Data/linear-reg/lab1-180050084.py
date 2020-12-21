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
	# print(X,Y,W)
	mse = np.sum(np.square(np.dot(X,W)-Y))/(2*(Y.shape[0]))
	# print(mse)

	## END TODO

	return mse

# print(mse(np.array([[1,2],[3,4]]),np.array([1,1]),np.array([1,1])))

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.04, max_iter=2000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	W = np.random.normal(0,1,size = (X_train.shape[1],1))
	## END TODO
	for i in range(max_iter):
		# print("#############")
		# print(W)
		# print("#############")

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)########################

		## TODO: Update w and b using a single step of gradient descent
		B = (X_train@W-Y_train)
		# print((np.dot(np.transpose(X_train),B))/(Y_train.shape[0]))
		W = W - lr*((X_train.T)@B)/(Y_train.shape[0])
		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.0075, max_iter=100):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	W = np.random.normal(0,0.5,size=(X_train.shape[1],1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W) 
		test_mse = mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		B = (X_train@W)-Y_train
		W = W - lr*((X_train.T)@B)/(Y_train.shape[0]) - 2*lr*reg*W
		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	n = r.shape[0]
	R = np.zeros((n,n))
	for i in range(n):
		R[i,i] = r[i]
	X = R@X
	Y = R@Y
	A = (np.transpose(X))@Y
	B = np.linalg.inv(np.transpose(X)@X)
	W = B@A

	## END TODO
	return W


if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('modified_data_4.csv')
	# X = X.astype('f')
	X, Y = preprocess(X, Y)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)


	W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	# plt.figure(figsize=(4,4))
	# plt.plot(train_mses)
	# plt.plot(test_mses)
	# plt.legend(['Train MSE', 'Test MSE'])
	# plt.xlabel('Iteration')
	# plt.ylabel('MSE')
	# plt.show()
	# print(train_mses[-1])
	# W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)
	# print(W_ridge)
	# print("########")
	# print(train_mses)
	
	# print(weighted_regression(X,Y,np.ones(Y.shape[0])))

	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()

