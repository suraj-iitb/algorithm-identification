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
		ind = np.random.randint(data.shape[0],size=self.n_clusters)
		self.cluster_centers = data[ind,:]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		dist = np.sum(np.square(self.cluster_centers-x),axis=1)
		return np.argmin(dist)
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			n = data.shape[0]
			P = np.zeros((self.n_clusters,n),dtype='bool')

			### Update labels for each point
			for j in range(n):
				i = self.pred(data[j])
				P[i,j] = 1				

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			cc = np.zeros(self.cluster_centers.shape)
			for i in range(self.n_clusters):
				sm = np.dot(P[i],data)
				d = np.sum(P[i])
				if d==0:
					cc[i] = self.cluster_centers[i]
					continue
				cc[i] = sm/d

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			dist = np.sum(np.square(self.cluster_centers-cc),axis=1)
			if np.all(dist < epsilon):
				break
			
			self.cluster_centers = cc[:]
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

