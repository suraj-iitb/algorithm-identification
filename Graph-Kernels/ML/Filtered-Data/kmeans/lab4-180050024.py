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
		n=data.shape[0]
		np.random.seed(2)
		n1=np.random.choice(n,self.n_clusters,replace=False)
		self.cluster_centers=data[n1,:]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		x.shape=[1,x.shape[0]]
		ans=self.cluster_centers-x
		ans=np.sum(np.square(ans),axis=1,keepdims=True)
		return np.argmin(ans)
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			labels=np.array([])
			### Update labels for each point
			labels=np.array([self.pred(x1) for i,x1 in enumerate(data)])

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			old_centers=np.copy(self.cluster_centers)
			for j in range(self.n_clusters):
				b=data[(labels==j),:]
				if b.shape[0] != 0:
					self.cluster_centers[j:j+1,:]=np.sum(b,axis=0,keepdims=True)/b.shape[0]

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			old_centers=self.cluster_centers - old_centers
			dists=np.sum(np.square(old_centers),axis=1,keepdims=True)
			dists=dists**0.5
			dists=np.sum((dists>=epsilon).astype(int))
			if dists==0:
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
	parser.add_argument('--k', default=2, type=int)

	args = parser.parse_args()

	image = plt.imread(f'data/{args.image}.png')
	x = image.reshape(-1, 3)
	kmeans = KMeans(D=3, n_clusters=args.k)
	kmeans.init_clusters(x)
	kmeans.train(x)
	out = kmeans.replace_by_center(x)
	plt.imshow(out.reshape(image.shape))
	plt.show()

