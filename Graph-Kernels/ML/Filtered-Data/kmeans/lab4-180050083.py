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
		self.cluster_centers = data[:self.n_clusters,:]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		return np.argmin(np.linalg.norm(self.cluster_centers - x, axis = 1))
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			new_centers = np.zeros(self.cluster_centers.shape)
			point_count = np.zeros(self.n_clusters)
			### Update labels for each point
			for i in range(data.shape[0]):
				num = self.pred(data[i])
				new_centers[num] = ((new_centers[num]*point_count[num])+data[i])/(point_count[num]+1)
				point_count[num] = point_count[num] + 1

			for i in range(self.n_clusters):
				if point_count[i] == 0:
					new_centers[i] = self.cluster_centers[i]
			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center


			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			if np.max(np.linalg.norm(new_centers - self.cluster_centers, axis = 1)) < epsilon:
				break
			else:
				self.cluster_centers = new_centers
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

