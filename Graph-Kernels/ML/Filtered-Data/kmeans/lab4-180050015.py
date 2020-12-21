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

		points = np.random.choice(data.shape[0], self.n_clusters, replace=False)
		self.cluster_centers = data[points, :]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		temp = np.sum((self.cluster_centers - x)** 2, axis=1)
		return np.argmin(temp)
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			n = data.shape[0]
			# print(it)
			new_clusters = np.zeros((self.n_clusters, data.shape[1]))
			count = np.zeros((self.n_clusters,)).astype(int)
			# A = np.sum(data ** 2, axis=1)
			B = np.sum(self.cluster_centers ** 2, axis=1)
			C = np.zeros((n, self.n_clusters))
			C += np.sum(data ** 2, axis=1)[:, np.newaxis]
			C += B
			C -= 2 * data.dot(self.cluster_centers.transpose())
			belong = np.argmin(C, axis=1)
			
			### Update labels for each point
			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			for i in range(n):
				new_clusters[belong[i],:] += data[i,:]
				count[belong[i]] += 1
			# print(count)
			# print(count.shape)
			update = np.nonzero(count)[0]
			# print(update)
			next_val = np.copy(self.cluster_centers)
			# print(next_val.shape)
			next_val[update, :] = new_clusters[update, :] / count[update][:, np.newaxis]
			dist = np.sqrt(np.sum((next_val - self.cluster_centers)** 2, axis=1))
			if (np.linalg.norm(dist, np.inf) < epsilon):
				break
			self.cluster_centers = next_val
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon

			### END TODO
		# print(it)
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

