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
		m = data.shape[0]
		n_clusters = self.n_clusters
		self.cluster_centers = np.asarray(data[np.random.choice(m,n_clusters)])
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		return np.argmin(np.sum(np.square(self.cluster_centers - x), axis = 1))
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			n_clusters = self.n_clusters
			old_centers = np.asarray(self.cluster_centers)

			#print(it)

			data_temp = np.tile(data.reshape((data.shape[0],data.shape[1],1)),(1,1,self.n_clusters))
			centers_temp = np.tile(old_centers.T,(1,1,1))
			### Update labels for each point
			labels = data_temp - centers_temp
			labels = np.sum(np.square(labels),axis = 1)
			labels = np.argmin(labels,axis=-1)


			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			
			self.cluster_centers = [data[labels == i].mean(axis=0) if (labels == i).any() else self.cluster_centers[i,:] for i in range(n_clusters)]			
			self.cluster_centers = np.squeeze(self.cluster_centers)
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			
			if np.sum(np.square(self.cluster_centers - old_centers), axis = 1).all() < epsilon:
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


	'''image = plt.imread(f'data/{args.image}.png')
	x = image.reshape(-1, 3)
	kmeans = KMeans(D=3, n_clusters=args.k)
	kmeans.init_clusters(x)
	kmeans.train(x)
	out = kmeans.replace_by_center(x)
	plt.imshow(out.reshape(image.shape))
	plt.show()

	x1 = x.copy()'''

	for i in range(1,4):
		for j in [2,5,10]:
			image = plt.imread(f'data/{i}.png')
			x = image.reshape(-1, 3)
			#print((x-x1).sum())
			kmeans = KMeans(D=3, n_clusters=j)
			kmeans.init_clusters(x)
			kmeans.train(x)
			out = kmeans.replace_by_center(x)
			plt.imshow(out.reshape(image.shape))
			plt.show()

