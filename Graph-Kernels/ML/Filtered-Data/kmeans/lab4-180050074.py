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


		number_of_rows = data.shape[0]
		random_indices = np.random.choice(number_of_rows, size=self.n_clusters, replace=False)

		self.cluster_centers = data[random_indices, :]

		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center

		a = self.cluster_centers - x
		a = np.sum(a**2,axis = 1)
		# a = np.apply_along_axis(np.linalg.norm, 1, a)
		
		return np.argmin(a)

		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables

			self.arr = np.zeros(self.n_clusters)


			### Update labels for each point

			self.arr = np.apply_along_axis(self.pred, 1, data)


			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center

			temp = np.empty((0,data.shape[1]), float)
			for i in range(self.n_clusters):
				b = np.where(self.arr==i)[0]
				b = data[b,:]
				if b.shape[0]!=0:
					b = np.sum(b,axis=0)/b.shape[0]
					b= b.reshape([1,data.shape[1]])
					temp = np.append(temp, b, axis=0)
				else:
					b = self.cluster_centers[i,:]
					b= b.reshape([1,data.shape[1]])
					temp = np.append(temp, b, axis=0)

			old = self.cluster_centers
			self.cluster_centers = temp
		

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon

			check = old - temp
			check = np.linalg.norm(check,axis = 1)
			# check = np.absolute(check)
			check  = np.amax(check)

			# print(temp)
			# print(old)
			# print(check)

			if check<epsilon:
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

