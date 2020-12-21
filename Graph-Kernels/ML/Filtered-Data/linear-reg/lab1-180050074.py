import numpy as np
import matplotlib.pyplot as plt
from utils import load_data2, split_data, preprocess, normalize
from numpy.linalg import inv

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



	A = np.matmul(X,W) - np.reshape(Y,X.shape[0])



	mse = np.matmul(A.transpose(),A)/(2*X.shape[0])


	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.001, max_iter=5000):#lr=0.00001, max_iter=2000
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 

	N = X_train.shape[0]

	W = np.random.normal(0, 0.01, X_train.shape[1])

	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE

		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)


		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent

		W = W - (lr*(np.matmul(  X_train.transpose(), np.matmul(X_train,W)-np.reshape(Y_train,N))))/N




		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.0001, max_iter=5000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal

	N = X_train.shape[0] 

	W = np.random.normal(0, 0.01, X_train.shape[1])

	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE

		train_mse = mse(X_train,Y_train,W) #+ reg*np.sum(W*W)
		test_mse = mse(X_test,Y_test,W) #+ reg*np.sum(W*W)

		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent


		W = W - lr*(((np.matmul(  X_train.transpose(), np.matmul(X_train,W)-np.reshape(Y_train,N)))/N) + ((2*reg)*W)/(1))

		
		## END TODO

	W = np.reshape(W,(W.shape[0],1))	

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO


	R = np.diag(r)
	R2 = np.matmul(R,R) #This is basically R^2 (R square)

	A = np.matmul(X.transpose(),np.matmul(R2,X))
	B = np.matmul(X.transpose(),np.matmul(R2,Y))

	W = np.matmul(inv(A),B)

	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)

	#W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)

# 	# Plots
# plt.figure(figsize=(4,4))
# plt.plot(train_mses)
# plt.plot(test_mses)
# plt.legend(['Train MSE', 'Test MSE'])
# plt.xlabel('Iteration')
# plt.ylabel('MSE')
# plt.show()

