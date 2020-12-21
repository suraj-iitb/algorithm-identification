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
		size = self.cluster_centers.shape[0]
		for i in range(size):
			self.cluster_centers[i]=data[i]
		 
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		index = 0 
		mini = np.linalg.norm(self.cluster_centers[0]-x)
		size = self.cluster_centers.shape[0]
		for i in range(1,size):
			dist = np.linalg.norm(self.cluster_centers[i]-x)
			if dist < mini:
				mini = dist
				index=i
		return index
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			n = data.shape[0]
			size = self.cluster_centers.shape[0]
			point_lables = np.zeros([n,])
			old = self.cluster_centers.copy()
			all_done = True
			### Update labels for each point
			for i in range(n):
				point_lables[i]=self.pred(data[i])

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			for i in range(size):
				count = 0
				data_part = np.zeros(self.cluster_centers.shape[1])
				for j in range(n):
					if(point_lables[j]==i):
						count+=1
					pass
				if(count!=0):
					for j in range(n):
						if(point_lables[j]==i):
							#print(data_part.shape)
							#print(data[j].shape)
							data_part+=data[j]
					self.cluster_centers[i]=data_part/count
				pass

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			for i in range(size):
				if np.linalg.norm(self.cluster_centers[i]-old[i])>epsilon :
					all_done = False
				pass

			if all_done == True :
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

