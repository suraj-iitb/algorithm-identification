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
		dis = np.sum(np.square(self.cluster_centers - x),axis=1)
		id = np.argmin(dis)
		return id
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			new_clusters = np.zeros_like(self.cluster_centers)
			n = data.shape[0]
			P = np.zeros((n,self.n_clusters))
			### Update labels for each point
			for i in range(n):
				P[i][self.pred(data[i])] = 1
			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			Z1 = (data.T@P).T
			Z2 = np.sum(P,axis=0)
			# print(Z1.shape)
			# print(Z2.shape)
			for i in range(self.n_clusters):
				if Z2[i]!=0:
					new_clusters[i] = Z1[i]/Z2[i]
				else:
					new_clusters[i] = self.cluster_centers[i]
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			dis = np.sum(np.square(new_clusters-self.cluster_centers),axis=1)
			conv = np.sum(dis<epsilon*epsilon)
			# print(conv)
			if conv == self.n_clusters:
				break
			else:
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
