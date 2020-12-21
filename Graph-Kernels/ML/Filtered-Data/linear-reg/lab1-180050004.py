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
	n=X.shape[0]

	X=X.astype(float)
	a=(np.dot(X,W)-Y)
	mse1=(1/(2*n))*((np.dot(a.T,a)))[0]
	## END TODO

	return mse1

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.065, max_iter=1000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	W=np.random.normal(0,1,(X_train.shape[1],1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse=mse(X_train,Y_train,W)
		test_mse=mse(X_test,Y_test,W)

		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		n=X_train.shape[0]
		grad=(1/n)*(np.dot((np.dot(X_train,W)-Y_train).T,X_train))
		#print(grad.T)
		#print(grad.T.shape)
		#print(W)
		#print(W.shape)
		W=W-lr*(grad.T)
		#print("-----")
		## END TODO
	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.01, max_iter=200):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	# W=np.zeros((X_train.shape[1],1))
	W=np.random.normal(0,1,(X_train.shape[1],1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		# print(reg)
		# print(X_train.shape[0])
		train_mse=mse(X_train,Y_train,W)
		test_mse=mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		n=X_train.shape[0]
		grad=(1/n)*(np.dot((np.dot(X_train,W)-Y_train).T,X_train))+2*reg*W.T
		#print(W)
		W=W-lr*(grad.T)
		## END TODO
	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	# X - numpy array of shape (n_samples, n_features)
	# Y - numpy array of shape (n_samples, 1)
	# W - numpy array of shape (n_features, 1)
	# r - numpy array of shape (n_samples, )
	r=r.reshape(r.shape[0],1)
	phi=np.diag(r.T[0])@X
	yn=np.diag(r.T[0])@Y
	ws=np.linalg.inv(phi.T @ phi) @ phi.T @ yn
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

