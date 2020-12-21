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
		indices = np.random.choice(data.shape[0],self.n_clusters)
		self.cluster_centers = data[indices].reshape(self.cluster_centers.shape)
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		return np.argmin(np.linalg.norm(self.cluster_centers-x,axis=1),axis=0)
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			
			vals = []
			iter=0

			for i in range(self.n_clusters):
				vals.append([])


			cent = []
			bugg=0
			br=0
			for i in range(data.shape[0]):
				vals[self.pred(data[i,:])].append(data[i,:])
			for idx,label_list in enumerate(vals):
				if not(label_list):

					iter=iter+1
					cent.append(self.cluster_centers[idx])
				else:

					bugg=bugg+1
					cent.append(np.sum(label_list,axis=0)/len(label_list))
			if np.all(np.linalg.norm(cent-self.cluster_centers)<epsilon):
				br=br+1
				break
			self.cluster_centers=np.array(cent).reshape(self.cluster_centers.shape)
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

