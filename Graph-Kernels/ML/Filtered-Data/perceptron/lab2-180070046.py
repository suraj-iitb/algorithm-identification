import numpy as np
import argparse
import matplotlib.pyplot as plt

def get_data(dataset,num_train_samples=-1):
	datasets = ['D1', 'D2']
	assert dataset in datasets, "Dataset {dataset} not supported. Supported datasets {datasets}"
	X_train = np.loadtxt(f'data/{dataset}/training_data')
	Y_train = np.loadtxt(f'data/{dataset}/training_labels', dtype=int)
	X_test = np.loadtxt(f'data/{dataset}/test_data')
	Y_test = np.loadtxt(f'data/{dataset}/test_labels', dtype=int)

	return X_train[:num_train_samples,:], Y_train[:num_train_samples], X_test, Y_test

class Perceptron():
	def __init__(self, C, D):
		'''
		C - number of classes
		D - number of features
		'''
		self.C = C
		self.weights = np.zeros((C, D))
		
	def pred(self, x):
		'''
		x - numpy array of shape (D,)
		'''
		### TODO: Return predicted class for x
		return np.argmax(np.matmul(self.weights,x))
		### END TODO

	def train(self, X, Y, max_iter=2):
		for _ in range(max_iter):
			for i in range(X.shape[0]):
				### TODO: Update weights
				#f = X[i].reshape((X[i].shape[0],1))
				pred = np.argmax(np.matmul(self.weights,X[i]))
				if pred != Y[i]:
					self.weights[pred] -= X[i]
					self.weights[Y[i]] += X[i]
				#print(pred,Y[i])
				### END TODO

	def eval(self, X, Y):
		n_samples = X.shape[0]
		correct = 0
		for i in range(X.shape[0]):
			if self.pred(X[i]) == Y[i]:
				correct += 1
		return correct/n_samples

if __name__ == '__main__':
	parser = argparse.ArgumentParser(description='Problem 4')
	parser.add_argument('--num_samples', type=int, default=-1,
					help='Number of samples to train on')
	args = parser.parse_args()
	
	num_train_samples = args.num_samples

	X_train, Y_train, X_test, Y_test = get_data('D1',num_train_samples)

	C = max(np.max(Y_train), np.max(Y_test))+1
	D = X_train.shape[1]

	perceptron = Perceptron(C, D)

	perceptron.train(X_train, Y_train)
	acc = perceptron.eval(X_test, Y_test)
	print(f'Test Accuracy: {acc}')

	train_sizes = [10,100,1000,10000,50000,80000]
	test_error = []
	
	def make_plots():
		for train_size in train_sizes:
			perceptron = Perceptron(C, D)
			X_train, Y_train, X_test, Y_test = get_data('D1',train_size)

			perceptron.train(X_train, Y_train)
			acc = perceptron.eval(X_test, Y_test)
			print(f'Test Accuracy: {acc}')
			test_error.append(1-acc)
		print(test_error)

		plt.figure()
		plt.plot(train_sizes, test_error)
		plt.title('Perceptron')
		plt.xlabel('Training Set Size')
		plt.ylabel('Test Error')
		plt.xscale('log')
		plt.show()

	#make_plots()