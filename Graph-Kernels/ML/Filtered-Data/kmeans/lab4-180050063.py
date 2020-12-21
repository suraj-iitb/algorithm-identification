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
		self.cluster_centers = data[np.random.choice(np.shape(data)[0], self.n_clusters),:]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		x = np.reshape(x,(-1,1))
		return np.argmin(np.sum(self.cluster_centers*self.cluster_centers,axis=1,keepdims=True)+np.sum(x*x)-2*(self.cluster_centers@x))
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			membership = np.zeros(np.shape(data)[0])
			new_centers = np.zeros((self.n_clusters, np.shape(data)[1]))
			new_centers[:] = self.cluster_centers[:]

			### Update labels for each point
			a = np.sum(data*data,axis=1,keepdims=True)
			b = np.sum(self.cluster_centers*self.cluster_centers,axis=1,keepdims=True).T
			membership = np.argmin(a+b-2*(data@(self.cluster_centers.T)),axis=1)

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			for i in range(self.n_clusters):
				temp = membership==i
				if np.sum(temp)==0:
					continue
				new_centers[i,:] =  np.sum(data[temp,:],axis=0)/(np.sum(temp))

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			flag = 1
			for i in range(self.n_clusters):
				if np.linalg.norm(self.cluster_centers[i,:]-new_centers[i,:]) >= epsilon:
					flag = 0
					break
			self.cluster_centers[:] = new_centers[:]
			if flag==1:
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
