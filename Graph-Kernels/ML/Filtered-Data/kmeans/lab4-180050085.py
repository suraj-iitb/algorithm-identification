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
		index = np.random.choice(data.shape[0], self.n_clusters, replace=False)
		self.cluster_centers = data[index]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		diff = np.sum((self.cluster_centers-x)**2, axis=1)
		return np.argmin(diff)
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			prev_centroids = self.cluster_centers.copy()
			labels = np.zeros((data.shape[0], 1))
			
			### Update labels for each point
			points = np.sum(data**2, axis=1).reshape(-1, 1)
			center = np.sum(prev_centroids**2, axis=1).reshape(1, -1)
			diff = points + center - 2*data@prev_centroids.T
			labels = np.argmin(diff, axis=1)

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			centroids = np.zeros(prev_centroids.shape)
			count = np.zeros((prev_centroids.shape[0], 1))
			for i in range(centroids.shape[0]):
				p = data[labels==i]
				if p.shape[0]!=0:
					centroids[i, :] = np.mean(p, axis=0)
				else:
					centroids[i, :] = prev_centroids[i, :]
			self.cluster_centers = centroids.copy()

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			if np.all(np.abs(self.cluster_centers-prev_centroids)<epsilon):
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
	parser.add_argument('--image', default='1', choices=['1', '2', '3'])
	parser.add_argument('--k', default=5, type=int)

	args = parser.parse_args()

	image = plt.imread(f'data/{args.image}.png')
	x = image.reshape(-1, 3)
	kmeans = KMeans(D=3, n_clusters=args.k)
	kmeans.init_clusters(x)
	kmeans.train(x)
	out = kmeans.replace_by_center(x)
	plt.imshow(out.reshape(image.shape))
	plt.show()

