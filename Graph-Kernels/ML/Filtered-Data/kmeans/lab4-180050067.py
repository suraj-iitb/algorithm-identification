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
		Z = np.random.choice(data.shape[0], self.n_clusters)
		self.cluster_centers = np.copy(data[Z])
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		Z = np.linalg.norm(self.cluster_centers[np.newaxis,:,:] - x, axis=-1)
		return np.argmin(Z, axis=1)
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			new_centers = np.copy(self.cluster_centers)

			### Update labels for each point
			labels = self.pred(data[:,np.newaxis,:])
			
			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			for i in range(self.n_clusters):
				members = data[labels == i]
				if members.size != 0:
					new_centers[i] = np.mean(members, axis=0)

			max_dist = np.max(np.linalg.norm(self.cluster_centers - new_centers, axis=1))
			self.cluster_centers = new_centers
			
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			if max_dist < epsilon:
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

	# plots generator code
	# images = ['1', '2', '3']
	# clusters = [2, 5, 10]
	# for img in images:
	# 	for cluster in clusters:
	# 		image = plt.imread(f'data/{img}.png')
	# 		x = image.reshape(-1, 3)
	# 		kmeans = KMeans(D=3, n_clusters=cluster)
	# 		kmeans.init_clusters(x)
	# 		kmeans.train(x)
	# 		out = kmeans.replace_by_center(x)
	# 		plt.imshow(out.reshape(image.shape))
	# 		plt.title(f'Clusters : {cluster}')
	# 		plt.savefig(f'outputs/image_{img}_clusters_{cluster}.png', bbox_inches='tight')
	# 		plt.clf()
