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
	mse = np.sum(np.square(Y-np.dot(X,W)))/(2*n)
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.001, max_iter=2000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal
	n_features = X_train.shape[1]
	n = X_train.shape[0] 
	W=np.random.normal(0,0.1,size=(n_features,1))
	# print(W.shape)

	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)
		# W=0
		## TODO: Update w and b using a single step of gradient descent
		# print(X_train.shape)
		pro = np.dot(X_train.transpose(),X_train)
		prow = np.dot(pro,W)
		pro1 = np.dot(X_train.transpose(),Y_train)
		W = W - (lr/n)*(prow-pro1)
		## END TODO

	return W, train_mses, test_mses

# X, Y = load_data2('data2.csv')
# X, Y = preprocess(X, Y)
# X_train, Y_train, X_test, Y_test = utils.split_data(X, Y)
# W, train_mses, test_mses = multi_var_reg.ordinary_least_squares(X_train, Y_train, X_test, Y_test)

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.001, max_iter=2000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	n_features = X_train.shape[1]
	n = X_train.shape[0] 
	W=np.random.normal(0,0.15,size=(n_features,1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		pro = np.dot(X_train.transpose(),X_train)
		prow = np.dot(pro,W)
		pro1 = np.dot(X_train.transpose(),Y_train)
		W = W - (lr/n)*(prow-pro1) -lr*2*reg*W
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
	R = np.diag(r,0)
	R2 = R*R
	pro = np.dot(np.dot(X.transpose(),R2),X)
	pro1 = np.dot(np.dot(X.transpose(),R2),Y)
	W = np.dot(np.linalg.inv(pro),pro1)
	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)
	W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	# r = np.random.normal(0,0.15,size=(X_train.shape[0],1))
	# w = weighted_regression(X,Y,r)
	# print(w)
	# print(train_mses[-1])
	# print(test_mses[-1])
	# W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)

	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()

