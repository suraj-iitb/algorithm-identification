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
		x.shape = [1,x.shape[0]]
		diff = self.cluster_centers-x
		diff= np.sum(np.multiply(diff,diff),axis=1)
		return np.argmin(diff)
		# ind = np.where(diff==np.amin(diff))[0][0]
		# return ind
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			m=data.shape[0]
			cluster_val = np.zeros((m,1))  

			### Update labels for each point
			for i in range(m):
				cluster_val[i,0] = self.pred(data[i,:])
			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			old_cluster_centers = np.copy(self.cluster_centers)
			for i in range(self.n_clusters):
				count=0
				cor_sum = np.zeros((1,data.shape[1]))
				for j in range(m):
					if(cluster_val[j]==i):
						count=count+1
						cor_sum = cor_sum+data[j,:].reshape(1,data.shape[1])
				if(count!=0):
					self.cluster_centers[i,:] = cor_sum/count

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			sq_dist=np.sum(np.power(self.cluster_centers-old_cluster_centers,2),axis=1)
			if self.n_clusters==np.sum(sq_dist < epsilon*epsilon):
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

