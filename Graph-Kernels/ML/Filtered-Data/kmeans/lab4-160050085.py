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
		self.cluster_centers = data[np.random.choice(data.shape[0], size=self.n_clusters, replace=False)]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		return np.argmin(np.sum((self.cluster_centers - x)**2, axis=1))
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			# print(it)
			### TODO
			### Declare and initialize required variables
			
			### Update labels for each point
			# new_labels = np.array([self.pred(d) for d in data])
			new_labels = np.argmin(np.sum((data - self.cluster_centers[:, np.newaxis])**2, axis=2), axis=0)
					
			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			new_centers = np.array([data[new_labels == k].mean(axis = 0) for k in range(self.n_clusters)])
			

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			
			distances = np.sqrt(np.sum((new_centers - self.cluster_centers)**2, axis=1))
			if np.min(distances) < epsilon:
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
	# print(x)
	kmeans = KMeans(D=3, n_clusters=args.k)
	kmeans.init_clusters(x)
	kmeans.train(x)
	out = kmeans.replace_by_center(x)
	plt.imshow(out.reshape(image.shape))
	plt.show()
	# plt.savefig(f'{args.image}-{args.k}.png')


