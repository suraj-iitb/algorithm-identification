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
	sub=np.matmul(X,W)-Y
	mse=sum(sub*sub)/(2*X.shape[0])
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.01, max_iter=5000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	W=np.random.normal(0,1,size=(X_train.shape[1],1))
	N=X_train.shape[0]
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse=mse(X_train,Y_train,W)
		test_mse=mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		W=W-lr*np.matmul(X_train.transpose(),(np.matmul(X_train,W)-Y_train))/N
		## END TODO

	# print(train_mses[-1])
	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.00005, max_iter=10000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	W=np.random.normal(0,1,size=(X_train.shape[1],1))
	N=X_train.shape[0]
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse=mse(X_train,Y_train,W)
		test_mse=mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		W=W-lr*(np.matmul(X_train.transpose(),(np.matmul(X_train,W)-Y_train))/N + 2*reg*W)
		## END TODO

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
	X=X.transpose()
	R=np.diag(r)
	R2=R*R
	# print(X.shape,R2.shape,Y.shape)
	W=np.matmul(X,np.matmul(R2,X.transpose()))
	# print(np.linalg.matrix_rank(W))
	W=np.linalg.inv(W)
	W=np.matmul(W,np.matmul(X,np.matmul(R2,Y)))
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

