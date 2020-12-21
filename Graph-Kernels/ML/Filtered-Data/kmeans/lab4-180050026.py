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

		i = np.random.choice(data.shape[0] , self.cluster_centers.shape[0])
		self.cluster_centers = data[i]


		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center

		init = np.linalg.norm(self.cluster_centers[0] - x)
		min_index = 0

		for i in range(self.cluster_centers.shape[0]):
			cur = np.linalg.norm(self.cluster_centers[i] - x)
			if cur < init :
				init = cur
				min_index = i

		return min_index

		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			prev_clusters = self.cluster_centers.copy()

			labels = np.zeros((data.shape[0] , 1))

			zero_count_bool = False

			### Update labels for each point
			for i in range(data.shape[0]):
				labels[i]= self.pred(data[i])

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			for i in range(self.cluster_centers.shape[0]):
				for j in range(data.shape[0]):
					if(labels[j] == i):
						zero_count_bool = True
						break

				if(zero_count_bool):
					count = 0
					new_cen = np.zeros((1,self.cluster_centers.shape[1]))
					for j in range(data.shape[0]):
						if(labels[j] == i):
							count = count +1 
							new_cen =  new_cen + data[j]
					prev_clusters[i] = self.cluster_centers[i]
					self.cluster_centers[i] = new_cen / count
					zero_count_bool = False




			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			breaker = False
			for i in range(self.cluster_centers.shape[0]):
				if ( (np.linalg.norm(self.cluster_centers[i] - prev_clusters[i])) >= epsilon ):
					break
				else:
					if (i == self.cluster_centers.shape[0] - 1) :
						breaker = True
			print(it)
			if(breaker):
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

