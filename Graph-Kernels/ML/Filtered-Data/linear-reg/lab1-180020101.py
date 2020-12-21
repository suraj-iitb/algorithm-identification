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
	# print(np.shape(X))
	# print(np.shape(W))
	# print(np.shape(Y))
	# a=np.multiply(X,W)-Y#np.transpose(np.multiply(X,W)-Y)
	b=np.matmul(X,W)
	a=(np.matmul(X,W)-Y)

	mse=np.linalg.norm(np.matmul(X,W)-Y)*np.linalg.norm(np.matmul(X,W)-Y)*1/(2*np.shape(Y)[0])
	# print("apple")
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.0001, max_iter=10000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	W=0.01*np.random.randn(np.shape(X_train)[1],1)
	# print(X_train)
	# W=np.zeros((np.shape(X_train)[1]))
	# print("b")
	# print(np.shape(W))
	# print("c")
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse=mse(X_train,Y_train,W)
		test_mse=mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		# a=np.matmul(np.transpose(X_train),(np.matmul(X_train,W)-Y_train))
		# b=np.multiply(np.matmul(np.transpose(X_train),(np.matmul(X_train,W)-Y_train)),1/(np.shape(Y_train)[0]))
		# print("z")
		# print(np.shape(W))
		# print("j")
		# a=np.transpose(X_train)
		# print(np.shape(a))
		# print("p")
		# print("q")
		# b=np.matmul(X_train,W)
		# print(np.shape(a))
		# print("l")
		# b=np.matmul(X_train,W)
		# print(np.shape(a))
		# print("o")
		# print("k")
		# b=(np.matmul(X_train,W)-Y_train)
		# print(np.shape(a))
		# print("m")
		# print(np.shape(np.multiply(np.matmul(np.transpose(X_train),(np.matmul(X_train,W)-Y_train)),1/(np.shape(Y_train)[0]))))
		# print("z")
		# time.sleep(100)
		# print(np.shape(X_train))
		# print(np.shape(W))
		# print(type(X_train[0][0]))
		# time.sleep(100)
		# X_train=X_train.astype()
		W=W-lr*np.multiply(np.matmul(np.transpose(X_train),(np.matmul(X_train,W)-Y_train)),1/(np.shape(Y_train)[0]))
		
		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.00001, max_iter=50000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	W=0.0001*np.random.randn(np.shape(X_train)[1],1)
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse=mse(X_train,Y_train,W)
		test_mse=mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		W=W-lr*np.multiply(np.matmul(np.transpose(X_train),(np.matmul(X_train,W)-Y_train)),1/(np.shape(Y_train)[0]))-2*lr*reg*W
		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	r_sq=np.square(r)
	R=np.diag(r_sq)
	W=np.matmul(np.linalg.inv(np.matmul(np.matmul(np.transpose(X),R),X)),np.matmul(np.matmul(np.transpose(X),R),Y))
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

