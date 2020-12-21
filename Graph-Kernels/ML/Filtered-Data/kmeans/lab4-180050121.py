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
		n, D = data.shape
		self.cluster_centers = data[np.random.choice(n, self.n_clusters, replace=False), :]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		return np.argmin(np.sum((self.cluster_centers - x)**2, axis=1))
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			n, D = data.shape
			cct = np.zeros((self.n_clusters, D))
			csz = np.zeros(self.n_clusters)
			# print(it)
			### Update labels for each point
			tmp = self.cluster_centers[: , np.newaxis, :]
			preds = np.argmin(np.sum((data - tmp)**2, axis=2),axis=0)
			# print(preds.shape, n)
			# cct[list(preds), :] += data[list(range(n)), :]
			# csz[list(preds)] += 1
			# np.sum(data[preds==i, :], axis=0)
			for i in range(self.n_clusters):
				cct[i, :] = np.sum(data[preds==i, :], axis=0)
				csz[i] = np.sum(preds==i, axis=0)
				# cct[self.pred(data[i, :]), :] += data[i, :]
				# csz[self.pred(data[i, :])] += 1
			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			for i in range(self.n_clusters):
				if (csz[i]==0):
					cct[i, :] = self.cluster_centers[i, :]
				else:
					cct[i, :] = cct[i, :]/csz[i]
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			bl = np.sum((cct-self.cluster_centers)**2, axis=1)**0.5 < epsilon
			self.cluster_centers = cct
			if np.all(bl):
				# print("bea")
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
	parser.add_argument('--k', default=2, type=int)

	args = parser.parse_args()

	image = plt.imread(f'data/{args.image}.png')
	x = image.reshape(-1, 3)
	kmeans = KMeans(D=3, n_clusters=args.k)
	kmeans.init_clusters(x)
	kmeans.train(x)
	out = kmeans.replace_by_center(x)
	plt.imshow(out.reshape(image.shape))
	plt.show()
	st = "kmeans"+str(args.image)+str(args.k)+".png"
	plt.savefig(st)

