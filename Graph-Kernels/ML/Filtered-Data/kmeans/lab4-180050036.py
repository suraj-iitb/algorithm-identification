import argparse
import numpy as np
import matplotlib.pyplot as plt

np.random.seed(5927)

class KMeans():
	def __init__(self, D, n_clusters):
		self.n_clusters = n_clusters
		self.cluster_centers = np.zeros((n_clusters, D))

	def init_clusters(self, data):
		### TODO
		### Initialize cluster_centers using n_clusters points sampled from data
		n = data.shape[0]
		a = np.arange(n)
		np.random.shuffle(a)
		a = a[:self.n_clusters]
		self.cluster_centers = data[a]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		#assuming x is of shape 1 x D
		diff_ = np.linalg.norm(self.cluster_centers-x, axis = 1)
		return np.argmin(diff_)
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			N3 = data@((self.cluster_centers).T)
			N1 = np.multiply(data, data)
			N1 = np.sum(N1, axis = 1)
			N2 = np.multiply((self.cluster_centers), (self.cluster_centers))
			N2 = np.sum(N2, axis = 1)
			N3 = (-2)*N3
			N3 = N3 + N2
			N3 = (N3.T + N1).T

			# m = data.shape[0]
			# labels = np.zeros(m)

			### Update labels for each point
			labels = np.argmin(N3, axis = 1)
			# for i in range(m):
			# 	labels[i] = self.pred(data[i])

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			D = data.shape[1]
			new_cluster = np.zeros((self.n_clusters, D))
			new_cluster = np.copy(self.cluster_centers)
			for i in range(self.n_clusters):
				T1 = data[labels == i]
				if T1.shape[0] == 0:
					continue
				else:
					new_cluster[i] = np.mean(T1, axis = 0) 

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			diff = np.linalg.norm(new_cluster - self.cluster_centers, axis =1)
			diff = np.max(diff)
			if diff < epsilon:
				self.cluster_centers = new_cluster
				break
			else:
				self.cluster_centers = new_cluster

			### END TODO
		return it

	def replace_by_center(self, data):
		out = np.zeros_like(data)
		for i, x in enumerate(data):
			out[i] = self.cluster_centers[self.pred(x)]
		return out

if __name__ == '__main__':
	parser = argparse.ArgumentParser()
	parser.add_argument('--image', default='1', choices=['1', '2', '3'])
	parser.add_argument('--k', default=5, type=int)

	args = parser.parse_args()

	image = plt.imread(f'data/{args.image}.png')
	x = image.reshape(-1, 3)
	kmeans = KMeans(D=3, n_clusters=args.k)
	kmeans.init_clusters(x)
	it = kmeans.train(x)
	out = kmeans.replace_by_center(x)
	plt.imshow(out.reshape(image.shape))
	plt.show()

