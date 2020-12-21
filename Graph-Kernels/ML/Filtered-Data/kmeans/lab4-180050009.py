import argparse
import numpy as np
import matplotlib.pyplot as plt
from numpy.linalg import norm

np.random.seed(5927)

class KMeans():
	def __init__(self, D, n_clusters):
		self.n_clusters = n_clusters
		self.cluster_centers = np.zeros((n_clusters, D))

	def init_clusters(self, data):
		### TODO
		### Initialize cluster_centers using n_clusters points sampled from data
		random_index = np.random.permutation(data.shape[0])
		self.cluster_centers = data[random_index[:self.n_clusters]]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		mini = norm(x - self.cluster_centers[0])
		p = 0
		for i in range(1,self.n_clusters):
			rnorm = norm(x - self.cluster_centers[i])
			if(mini>rnorm):
				p = i

		return p

		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			N = data.shape[0]
			D = data.shape[1]
			labels = np.zeros(N)
			old = self.cluster_centers
			new = np.zeros((self.n_clusters,D))
			### Update labels for each point
			for i in range(N):
				labels[i] = self.pred(data[i])
			#print(labels)
			### Update cluster centers
			for i in range(self.n_clusters):
				ith = np.where(labels == i)[0]
				#print(ith)
				if(ith.shape[0] != 0):
					#print("aaaaa")
					new[i] = np.mean(data[ith],axis = 0)
					#print(self.cluster_centers[i])
				else:
					new[i] = old[i]

			# print(self.cluster_centers)
			# print("\n")
			### Note: If some cluster is empty, do not update the cluster center
			# print(old)
			# print(new)
			self.cluster_centers = new
			#print(self.cluster_centers)
			### Check for convergence
			t = 0
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			for i in range(self.n_clusters):
				diff = norm(self.cluster_centers[i] - old[i])
				# print(old[i])
				# print(self.cluster_centers[i])
				#print(diff)
				if(diff<epsilon):
					t = t + 1
				else:
					break
			
			if(t == self.n_clusters):
				break
			### END TODO
		return it

	def replace_by_center(self, data):
		out = np.zeros_like(data)
		for i, x in enumerate(data):
			out[i] = self.cluster_centers[self.pred(x)]
		return out

if __name__ == '__main__':
	parser = argparse.ArgumentParser()
	parser.add_argument('--image', default='3', choices=['1', '2', '3'])
	parser.add_argument('--k', default=10, type=int)

	args = parser.parse_args()

	image = plt.imread(f'data/{args.image}.png')
	x = image.reshape(-1, 3)
	kmeans = KMeans(D=3, n_clusters=args.k)
	kmeans.init_clusters(x)
	kmeans.train(x)
	out = kmeans.replace_by_center(x)
	plt.imshow(out.reshape(image.shape))
	plt.show()

