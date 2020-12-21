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

		rand_idx = np.random.randint(0, data.shape[0], (self.n_clusters))

		self.cluster_centers = data[rand_idx]

		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center

		diff = self.cluster_centers - x.T

		dist = np.sum(diff * diff, axis=1)

		return np.argmin(dist, axis=0)

		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables

			old_clusters = self.cluster_centers
			num_points = np.zeros(self.n_clusters)

			### Update labels for each point

			labels = [self.pred(x) for x in data]

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center

			self.cluster_centers = np.zeros_like(self.cluster_centers)

			for i, idx in enumerate(labels):
				self.cluster_centers[idx] += data[i]
				num_points[idx] += 1

			empty_clusters = num_points == 0
			self.cluster_centers[empty_clusters] = old_clusters[empty_clusters]

			self.cluster_centers[np.invert(empty_clusters)] /= num_points[np.invert(empty_clusters),np.newaxis]

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			
			diff2 = (self.cluster_centers - old_clusters)*(self.cluster_centers - old_clusters)
			diff2 = np.sum(diff2, axis=1)

			if np.all(diff2 < epsilon * epsilon):
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

