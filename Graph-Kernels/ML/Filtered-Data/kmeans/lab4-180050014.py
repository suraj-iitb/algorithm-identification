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
		shaper=np.shape(data)
		points = np.arange(shaper[0])
		np.random.shuffle(points)
		chosen = points[:self.n_clusters]
		self.cluster_centers = data[chosen]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		euclinorm = np.linalg.norm(x-self.cluster_centers,axis=1)
		return np.argmin(euclinorm)
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			shaperd=np.shape(data)
			tags = []
			updatedC = []
			tags = [[] for j in range(self.n_clusters)]
			### Update tags for each point
			for dataidx in range(shaperd[0]):
				datarow=data[dataidx][:]
				pred = self.pred(datarow)
				tags[pred].append(list(datarow))
			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			for i,label in enumerate(tags,start=0):
				shaper=np.shape(label)
				if label:
					updatedC.append(np.sum(label,axis=0)/shaper[0])
				elif not(label):
					updatedC.append(self.cluster_centers[i])
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			cond = (np.linalg.norm(self.cluster_centers - updatedC) < epsilon)
			if cond:
				break
			elif not(cond):
				self.cluster_centers = np.array(updatedC)
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

