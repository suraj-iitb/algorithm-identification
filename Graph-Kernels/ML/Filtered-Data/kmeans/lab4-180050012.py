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
		self.cluster_centers = data[np.random.choice(data.shape[0],self.n_clusters, replace=False)]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster centers
		return np.argmin(np.linalg.norm(self.cluster_centers-x,axis=1))
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			n = len(data)
			R = np.zeros([n,self.n_clusters])
			### Update labels for each point
			for i,x in enumerate(data):
				c = self.pred(x)
				R[i][c] = 1

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			temp = np.copy(self.cluster_centers)

			for c in range(self.n_clusters):
				if(np.sum(R[:,c])>0):
					self.cluster_centers[c] = np.average(data[R[:,c]==1],axis=0)

			if np.all(np.linalg.norm(self.cluster_centers-temp,axis=1)<epsilon):
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
	# choices=['1', '2', '3']
	# kc=[2,5,10]
	# for imagec in choices:
	# 	for k in kc:
	# 		image = plt.imread(f'data/{imagec}.png')
	# 		x = image.reshape(-1, 3)
	# 		kmeans = KMeans(D=3, n_clusters=k)
	# 		kmeans.init_clusters(x)
	# 		kmeans.train(x)
	# 		out = kmeans.replace_by_center(x)
	# 		plt.imshow(out.reshape(image.shape))
	# 		plt.show()

