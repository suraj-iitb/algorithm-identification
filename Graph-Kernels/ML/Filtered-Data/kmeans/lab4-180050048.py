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
		# print(self.cluster_centers[0].shape)
		l=np.random.choice(data.shape[0],self.n_clusters,replace=False)
		self.cluster_centers=data[l,:]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		# print(x.shape)
		temp = self.cluster_centers-x
		temp = temp*temp
		temp = np.sum(temp,axis=1)
		return np.argmin(temp)
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			# print(max_iter)
			temp=np.copy(self.cluster_centers)
			labels=np.zeros((data.shape[0],1))
			
			### Update labels for each point
			for i, x in enumerate(data):
				# print(i,x)
				labels[i] = self.pred(x)
			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			
			for i in range(self.n_clusters): 
				if(np.sum(labels==i)==0):
					continue
				self.cluster_centers[i,:]=np.mean(data[(labels==i).reshape(data.shape[0],),:],axis=0)
			
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			dist = temp-self.cluster_centers
			dist = dist*dist
			dist = np.sqrt(np.sum(dist,axis=1))
			if(np.max(dist)<epsilon):
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

