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
		self.cluster_centers = data[np.random.permutation(data.shape[0])[:self.n_clusters]]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		return np.argmin(np.linalg.norm(self.cluster_centers - x.reshape((1, -1)), axis = 1))
		### END TODO

	def train(self, data, max_iter=10, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			new_center_sum = np.zeros(self.cluster_centers.shape)
			label_count = np.zeros(self.n_clusters)
			### Update labels for each point
			for i in range(len(data)):
				label = self.pred(data[i])
				label_count[label] += 1
				new_center_sum[label] += data[i]
			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			for i in range(self.n_clusters):
				if label_count[i] == 0:
					new_center_sum[i] = self.cluster_centers[i]
				else:
					new_center_sum[i] /= label_count[i]
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			if np.max(np.linalg.norm(new_center_sum - self.cluster_centers, axis = 1)) < epsilon:
				break
			else:
				self.cluster_centers = new_center_sum
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
