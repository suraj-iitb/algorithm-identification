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
		self.cluster_centers = data[np.random.choice(np.arange(data.shape[0]),self.n_clusters,replace=False)]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center

		return int(np.argmin(np.linalg.norm(self.cluster_centers-x,axis=1)))
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		count = np.zeros((self.n_clusters,1))
		assign = np.zeros((data.shape[0])).astype(int)
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			mean = np.zeros((self.n_clusters,data.shape[1]))
			count = np.zeros((self.n_clusters,1))
			### Update labels for each point
			for i in range(data.shape[0]):
				assign[i] = self.pred(data[i])
				
				count[assign[i]]+=1
				mean[assign[i]]+=data[i]


			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			old_clusters = self.cluster_centers.copy()
			print(count,mean)
			for i in range(self.n_clusters):
				if(count[i]!=0):
					self.cluster_centers[i] = mean[i]/(count[i])
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			error = max(np.linalg.norm(self.cluster_centers-old_clusters,axis = 1))

			if(error<epsilon):
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
	k = [2,5,10]
	for K in k:
		for i in range(1,4):

			image = plt.imread(f'data/'+str(i)+'.png')
			x = image.reshape(-1, 3)
			kmeans = KMeans(D=3, n_clusters=K)
			kmeans.init_clusters(x)
			kmeans.train(x)
			out = kmeans.replace_by_center(x)
			plt.imshow(out.reshape(image.shape))
			plt.show()

