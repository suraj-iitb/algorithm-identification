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
		rand_arr = np.random.choice(data.shape[0], self.n_clusters)
		self.cluster_centers = data[rand_arr]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		dist = np.sum((self.cluster_centers - x) ** 2, axis=1)
		return np.argmin(dist)
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			old_centers = self.cluster_centers
			new_centers = np.zeros_like(self.cluster_centers)

			### Update labels for each point
			out1 = self.replace_by_center(data)

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			for i, _ in enumerate(new_centers):
				temp = np.sum(np.where(out1 == self.cluster_centers[i], 1, 0), axis=1)
				cluster_arr = np.where(temp == self.cluster_centers.shape[1], True, False)
				num_points = np.sum(cluster_arr)
				
				if (num_points != 0):
					new_centers[i] = np.sum(data[cluster_arr], axis=0) / num_points
				else:
					new_centers[i] = old_centers[i]

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			dist_centers = (np.sum((new_centers - old_centers) ** 2, axis=1)) ** (1 / 2)
			if (np.max(dist_centers) < epsilon):
				break
			self.cluster_centers = np.copy(new_centers)
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

