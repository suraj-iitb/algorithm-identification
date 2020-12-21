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
		diff = self.cluster_centers - x
		dissq = np.sum(diff*diff,axis=1).reshape(self.cluster_centers.shape[0],1)
		return np.argmin(dissq)
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			labels = np.zeros_like(data)

			### Update labels for each point
			for i, x in enumerate(data):
				labels[i] = self.pred(x)

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			cltctrnew = np.zeros_like(self.cluster_centers)
			cltptscnt = np.zeros(self.cluster_centers.shape[0])
			diff = np.zeros(self.cluster_centers.shape)
			for i, x in enumerate(data):
				cltctrnew[self.pred(x)]+=x
				cltptscnt[self.pred(x)]+=1

			for i, ctr in enumerate(self.cluster_centers):
				if cltptscnt[i]!=0:
					diff[i] = self.cluster_centers[i] - cltctrnew[i]/cltptscnt[i]
					self.cluster_centers[i] = cltctrnew[i]/cltptscnt[i]

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			if np.amax(np.sum(diff*diff,axis=1).reshape(self.cluster_centers.shape[0],1)) < epsilon*epsilon:
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

