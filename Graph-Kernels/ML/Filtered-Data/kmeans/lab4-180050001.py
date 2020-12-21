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
		idx = np.random.choice(data.shape[0], size = self.n_clusters, replace = False)
		self.cluster_centers = data[idx]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		distances = np.linalg.norm(self.cluster_centers-x, axis=1)
		# distances = np.sum(np.multiply(distances, distances), axis=1)
		ret = np.argmin(distances)
		return ret
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			# print(it)
			### Declare and initialize required variables
			points = np.zeros(data.shape[0]).reshape(-1)
			count_clusters = np.zeros(self.n_clusters).reshape(-1)
			temp = np.zeros((self.n_clusters, data.shape[1]))

			### Update labels for each point
			for i in range(data.shape[0]):
				points[i] = self.pred(data[i,:])
				count_clusters[int(points[i])] += 1
				temp[int(points[i])] += data[i]


			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			new_clusters = self.cluster_centers.copy()
			for i in range(self.n_clusters):
				if count_clusters[i] != 0:
					new_clusters[i] = temp[i]/count_clusters[i]


			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			if np.all(np.linalg.norm(self.cluster_centers - new_clusters, axis=1)< epsilon):
				break

			self.cluster_centers = new_clusters

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

