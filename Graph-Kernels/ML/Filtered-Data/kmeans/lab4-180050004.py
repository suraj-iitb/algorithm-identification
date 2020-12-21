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
		ind=np.random.choice(data.shape[0],size=(self.n_clusters,))
		self.cluster_centers=data[ind,:]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		d=np.sum((self.cluster_centers-x)**2,axis=1)
		ans=np.argmin(d)
		return ans
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			old=self.cluster_centers.copy()

			### Update labels for each point
			d=np.broadcast_to(data.reshape(data.shape[0],1,data.shape[1]),(data.shape[0],self.n_clusters,data.shape[1]))
			d=(d-self.cluster_centers)**2
			d=np.sum(d,axis=2)
			d=np.argmin(d,axis=1)
			labels=d
			### Update cluster centers
			for i in range(self.n_clusters):
				temp=data[labels==i,:]
				if(temp.shape[0]!=0):
					# print((np.sum(temp,axis=0))/temp.shape[0])
					# print("this")
					self.cluster_centers[i,:]=(np.sum(temp,axis=0))/temp.shape[0]
			### Note: If some cluster is empty, do not update the cluster center


			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			temp1=np.sqrt(np.sum( (old-self.cluster_centers)**2,axis=1) )
			if(np.all(temp1<epsilon)):
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

