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
		self.cluster_centers = np.array([data[i] for i in np.random.randint(0,data.shape[0],self.n_clusters)])
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		return np.argmin(np.linalg.norm(self.cluster_centers-x,axis=1))
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			# n = data.shape[0]
			# labels = np.zeros(n)
			new_centers = np.zeros(self.cluster_centers.shape)
			count_in_clusters = np.zeros((self.n_clusters,1))
			### Update labels for each point
			# labels = [self.pred(x) for x in data]

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			for x in data:
				l = self.pred(x)
				new_centers[l]+=x
				count_in_clusters[l]+=1
			for i in range(self.n_clusters):
				if count_in_clusters[i] == 0:
					new_centers[i] = self.cluster_centers[i]
					count_in_clusters[i] = 1
			new_centers = new_centers/count_in_clusters
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			if np.max(np.linalg.norm(self.cluster_centers-new_centers)) < epsilon :
				break
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
	parser.add_argument('--image', default='1', choices=['1', '2', '3','4'])
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

