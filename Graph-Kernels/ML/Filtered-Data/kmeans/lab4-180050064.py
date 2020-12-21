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
		x=range(data.shape[0])
		return data[np.random.choice(x, self.n_clusters,replace="None")]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		#print("pred",np.argmin(np.sum((x-self.cluster_centers)**2,axis=1)))
		return np.argmin(np.sum((x-self.cluster_centers)**2,axis=1))
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			labels=np.zeros((data.shape[0],self.n_clusters))
			old_centers=self.cluster_centers
			### Declare and initialize required variables

			for i in range(data.shape[0]):
				j=np.argmin(np.sum((data[i]-self.cluster_centers)**2,axis=1))
				labels[i][j]=1
			### Update labels for each point
			y=np.sum(labels,axis=0).reshape(self.n_clusters,1)
			self.cluster_centers=labels.T @ data
			for i in range(y.shape[0]):
				if y[i]==0:
					self.cluster_centers[i]=old_centers[i]
				else:
					self.cluster_centers[i]=self.cluster_centers[i]/y[i]
			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center


			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			if np.linalg.norm(self.cluster_centers-old_centers)<epsilon:
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
