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
	(n,m)=np.shape(X)
	mse= np.sum((Y-np.matmul(X,W))**2)/(2*n)
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.01, max_iter=10000):
	train_mses = []
	test_mses = []
	# lr=0.00001
	## TODO: Initialize W using using random normal 
	(n,f)=np.shape(X_train)
	W=np.random.normal(0,1,(f,1))
	## END TODO
	# print("multivar ols started")
	# print(n,f)
	for i in range(max_iter):
		# print(i)
		## TODO: Compute train and test MSE
		train_mse=mse(X_train,Y_train,W)
		test_mse=mse(X_test,Y_test,W)
		## END TODO
		# print("hello")
		train_mses.append(train_mse)
		test_mses.append(test_mse)
		# print("hello2")
		## TODO: Update w and b using a single step of gradient descent
		W=W-lr*(np.dot(np.dot(X_train.T,X_train),W)-np.dot(X_train.T,Y_train))/n
		# print("hello 3")
		# print(i)
		## END TODO
	# print(train_mses[-1],test_mses[-1])
	# print("ordinary least square complete")
	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.001, max_iter=10000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	(n,f)=np.shape(X_train)
	W=np.random.normal(0,1,(f,1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse=mse(X_train,Y_train,W)
		test_mse=mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		W=W-lr*(((np.dot(np.dot(X_train.T,X_train),W)-np.dot(X_train.T,Y_train))/n)+2*reg*W)
		## END TODO
	# print(train_mses[-1],test_mses[-1])
	
	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	R2=np.diag(r)**2
	W=np.dot(np.linalg.inv(np.dot(np.dot(X.T,R2),X)),np.dot(np.dot(X.T,R2),Y))

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

