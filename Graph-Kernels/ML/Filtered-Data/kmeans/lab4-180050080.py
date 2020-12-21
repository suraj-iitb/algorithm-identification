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
		for i in range(self.n_clusters):
			self.cluster_centers[i] = data[i]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		mymin = 100000
		ind = -1
		for i in range(self.n_clusters):
			if(np.linalg.norm(x-self.cluster_centers[i])<mymin):
				mymin = np.linalg.norm(x-self.cluster_centers[i])
				ind = i
		return ind
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			p = []
			old_clusters = self.cluster_centers.copy()
			for i in range(data.shape[0]):
				p.append(0)
			### Update labels for each point
			for i in range(data.shape[0]):
				p[i] = self.pred(data[i])
			### Update cluster centers
			for i in range(self.n_clusters):
				x = np.zeros(data[1].shape)
				mycount = 0
				for j in range(len(p)):
					if(p[j]==i):
						x = x+data[j]
						mycount += 1
				if(mycount!=0):
					self.cluster_centers[i] = x/mycount

			### Note: If some cluster is empty, do not update the cluster center
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			mydiff = np.linalg.norm(self.cluster_centers-old_clusters, axis=1)
			myflag = True
			for i in range(mydiff.shape[0]):
				if(mydiff[i]>0.0001):
					myflag = False
					break
			if(myflag):
				return it
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

