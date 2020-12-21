import numpy as np
import matplotlib.pyplot as plt
import math
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
	#xw = X.dot(W)
	xw = np.dot(X,W)
	h = np.size(xw,0)
	a =  (1/(2*h))

	dum = a*(xw-Y)
	#print(X)
	dum = np.matmul(dum.T,(xw-Y))
	mse = np.sum(dum)
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.001, max_iter=2000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	W = np.random.normal(0, 0.01, size=(np.size(X_train,1), 1))
	#X_train = X_train.astype(float)
	#X_test = X_test.astype(float)
	## END TODO
	
	#print(np.size(X_train,0))
	for i in range(max_iter):
		#w,W
		## TODO: Compute train and test MSE
		#print(2)
		train_mse = mse(X_train,Y_train,W)
		#print(1)
		test_mse = mse(X_test,Y_test,W)
		#print(train_mse)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		h = np.size(X_train,0)
		W = W - lr*(1/h)*(np.transpose(X_train).dot((X_train.dot(W)  - Y_train)))
		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.0001, max_iter=10000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	#print(4)
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	#print(3)
	W = np.random.normal(0, 0.01, size=(np.size(X_train,1), 1))
	X_train = X_train.astype(float)
	X_test = X_test.astype(float)
	## END TODO
	#print(2)
	for i in range(max_iter):
		# sqw = np.square(W)
		# sqwsum = np.sum(sqw)
		# print(sqwsum)
		# regw = reg*sqwsum
		#sqrtw = math.sqrt(sqwsum)
		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W) 
		#print(1)
		test_mse = mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		h = np.size(X_train,0)
		W = (1-lr*2*reg)*W - lr*(1/h)*(np.transpose(X_train).dot((X_train.dot(W)  - Y_train)))
		## END TODO
	#print(W)
	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	R = np.zeros((np.size(r,0),np.size(r,0)))
	for i in range(np.size(r,0)):
		R[i,i] = r[i,]*r[i,]
	w_new = np.linalg.inv(((X.T).dot(R.dot(X)))).dot((X.T).dot(R.dot(Y)))

	## END TODO
	return w_new

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

