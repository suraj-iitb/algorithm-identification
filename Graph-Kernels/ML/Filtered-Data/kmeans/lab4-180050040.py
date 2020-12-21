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
		a = data.shape[0]
		b = self.n_clusters
		c = replace=False
		d = np.random.choice(a, b, c)
		self.cluster_centers = data[d]
		
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		# f = x-centroid
		# e = np.linalg.norm(f)
		# temp1 = [e for centroid in self.cluster_centers]
		# g = min(temp1)
		# temp2 = temp1.index(g)
		# return temp2 
		distances = []
		for centroid in self.cluster_centers:
			a = x-centroid
			b = np.linalg.norm(a)
			distances.append(b)
		c = np.argmin(distances)

		return c
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for j1 in range(max_iter):
			### TODO
			### Declare and initialize required variables
			self.classi = {}

			for i in range(self.n_clusters):
				self.classi[i] = []

			### Update labels for each point
			for set1 in data:
				classi1=self.pred(set1)
				self.classi[classi1].append(set1)

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			
			first_c = self.cluster_centers.copy()

			for classi1 in self.classi:
				if(len(self.classi[classi1])!=0):
					e = self.classi[classi1]
					f = np.average(e,axis=0)

					self.cluster_centers[classi1] = f
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			temp3 = 1
			
			for c in range(self.n_clusters):
				g = self.cluster_centers[c]-first_c[c]
				h = np.linalg.norm(g)
				if h >= epsilon:
					temp3 = False
					
			if temp3:
				break 

			### END TODO
		return j1

	def replace_by_center(self, data):
		out = np.zeros_like(data)
		for i, x in enumerate(data):
			out[i] = self.cluster_centers[self.pred(x)]
		return out

if __name__ == '__main__':
	parser = argparse.ArgumentParser()
	parser.add_argument('--image', default='1', choices=['1', '2', '3'])
	parser.add_argument('--k', default=10, type=int)

	args = parser.parse_args()

	image = plt.imread(f'data/1.png')
	x = image.reshape(-1, 3)
	kmeans = KMeans(D=3, n_clusters=args.k)
	kmeans.init_clusters(x)
	kmeans.train(x)
	out = kmeans.replace_by_center(x)
	plt.imshow(out.reshape(image.shape))
	plt.show()
