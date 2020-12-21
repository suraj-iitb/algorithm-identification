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
		random_indices =  np.random.choice(data.shape[0], size=self.n_clusters, replace=False)
		self.cluster_centers = data[random_indices]
		### END TODO
	
	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		diff = self.cluster_centers-x
		dist = np.sum(np.power(diff,2),axis=1)
		assg = np.argmin(dist)
		return assg
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			prev_centers = np.copy(self.cluster_centers)

			### Update labels for each point
			xt = np.sum(data*data, axis=1).reshape(data.shape[0],1)
			ct = np.sum(self.cluster_centers*self.cluster_centers, axis=1).reshape(1,self.cluster_centers.shape[0])
			di = xt+ct-2*np.dot(data,self.cluster_centers.T)
			labels = np.argmin(di,axis=1) 

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			for i in range(self.n_clusters):
				x = (labels==i)
				count = np.sum(x)
				if count==0:
					continue
				self.cluster_centers[i] = np.sum(data[x],axis=0)/count

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			if np.linalg.norm(self.cluster_centers-prev_centers)<epsilon:
				break

			### END TODO
		return it
		# return it
	
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

