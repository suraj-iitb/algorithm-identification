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

	Y_hat=np.matmul(X,W)
	Y_hat=Y_hat-Y
	mse=np.dot(np.transpose(Y_hat),Y_hat)
	N=len(X)
	mse=mse/2
	mse=mse/N

	#print(mse.shape)

	mse=mse[0][0]

	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.01, max_iter=8000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	D=len(X_train[0])
	#print(max_iter)
	#print(len(X_train[0]))
	#print(len(X_test[0]))
	W=np.random.normal(size=(D, 1))
	#W=np.ones((D,1), dtype=int)
	#print(W.shape)
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE

		train_mse=mse(X_train,Y_train,W)
		test_mse=mse(X_test,Y_test,W)

		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)
		#print(test_mse)

		## TODO: Update w and b using a single step of gradient descent

		X=X_train
		Y=Y_train

		Y_hat=np.matmul(X,W)
		Y_hat=Y_hat-Y
		update=np.matmul(np.transpose(X),Y_hat)
		N=len(X_train)
		#print(N)
		update=update/N
		update=update*lr

		#print(update)

		W=W-update

		#print(W.shape)

		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.0001, max_iter=4000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	D=len(X_train[0])
	#print(len(X_train[0]))
	#print(len(X_test[0]))
	W=np.random.normal(size=(D, 1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse=mse(X_train,Y_train,W)
		test_mse=mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent

		X=X_train
		Y=Y_train

		Y_hat=np.matmul(X,W)
		Y_hat=Y_hat-Y
		update=np.matmul(np.transpose(X),Y_hat)
		N=len(X_train)
		#print(N)
		update=update/N

		update1=W
		update1=2*update1
		update1=reg*update1

		update=update+update1

		update=update*lr

		#print(update)

		W=W-update

		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO

	R=np.diag(r)
	R=np.matmul(R,R)
	M=np.matmul(np.transpose(X),R)
	M=np.matmul(M,X)
	W=np.linalg.inv(M)

	W=np.matmul(W,np.transpose(X))
	W=np.matmul(W,R)
	W=np.matmul(W,Y)

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