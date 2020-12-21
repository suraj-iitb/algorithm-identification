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
	V=Y_hat-Y
	ans=0
	n_samples=len(V)
	for i in range(n_samples):
		ans=ans+V[i]*V[i]
	ans=ans/(2*n_samples)
	mse=ans
	## END TODO
	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.05, max_iter=2200):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	A=np.shape(X_train)
	n_features=A[1]
	mean=0
	var=1
	W=np.random.normal(mean,var,n_features)
	W=W.reshape((len(W),1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		# print("iter ",i)
		train_mse=mse(X_train,Y_train,W)
		test_mse=mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		n_samples=len(Y_train)
		Y_hat=np.matmul(X_train,W)
		Y_hat=Y_hat.reshape((len(Y_hat),1))
		V=Y_hat-Y_train
		Q=X_train.transpose()
		D=np.matmul(Q,V)
		# print("X_train ",np.shape(X_train))
		# print("Y_hat ", np.shape(Y_hat))
		# print("Y_train ",np.shape(Y_train))
		# print("V ", np.shape(V))
		# print("W ", np.shape(W))
		# print("D", np.shape(D))
		W=W-lr*D/n_samples
	# print(train_mses[-1])
	# print(test_mses[-1])
	# print("------")
		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.01, max_iter=72):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	A=np.shape(X_train)
	n_features=A[1]
	mean=0
	var=1
	W=np.random.normal(mean,var,n_features)
	W=W.reshape((len(W),1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse=mse(X_train,Y_train,W)
		test_mse=mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		n_samples=len(Y_train)
		Y_hat=np.matmul(X_train,W)
		Y_hat=Y_hat.reshape((len(Y_hat),1))
		V=Y_hat-Y_train
		Q=X_train.transpose()
		D=np.matmul(Q,V)
		W=W-lr*(D/n_samples + 2*reg*W)
	# print(train_mses[-1])
	# print(test_mses[-1])
	# print("------")
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
	# print(np.shape(R))
	T1=X.transpose()
	# print(np.shape(X))
	T2=R.transpose()
	F=np.matmul(T1,T2)
	F=np.matmul(F,R)
	# print(np.shape(F))
	# print(type(F))
	# print(np.shape(X))
	# print(type(X))
	# print(F)
	# print("-------")
	# print(X)
	G1=np.matmul(F,X)
	G1=np.linalg.inv(G1)
	G2=np.matmul(F,Y)
	W=np.matmul(G1,G2)
	train_mse=mse(X_train,Y_train,W)
	test_mse=mse(X_test,Y_test,W)
	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)

	# W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)

	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()

