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
		# print(data.shape)
		idx = np.random.choice(data.shape[0],self.n_clusters,replace=False)
		# self.cluster_centers = data[:self.n_clusters , :]
		self.cluster_centers = data[idx,:]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		distance = np.linalg.norm( self.cluster_centers - x.reshape(1,x.shape[0]) , axis=1)
		return np.argmin(distance)
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			labels = np.zeros( (self.n_clusters , data.shape[0]) )
			old_centres = self.cluster_centers.copy()

			### Update labels for each point
			Y = self.cluster_centers.copy() 
			Yn = (Y*Y) @ np.ones((Y.shape[1],1))
			X = data.copy()
			Xn = (X*X) @ np.ones((X.shape[1] , 1))
			label = np.argmin(Xn + Yn.T - 2*X@(Y.T) , axis =1)
			# print(label.shape)
			label = label.reshape(1,label.shape[0])
			labels[label,np.array(range(data.shape[0]))] = 1
			# for i in range(data.shape[0]):1
				# x = data[i,:]
				# diff = self.cluster_centers - x.reshape(1,x.shape[0])
				# distance = np.sum(diff*diff , axis = 1)
				# labels[np.argmin(distance)][i] = 1 

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			num_points_each_class = np.sum(labels , axis=1)
			for i in range(self.n_clusters):
				if num_points_each_class[i] != 0:
					self.cluster_centers[i,:] = np.sum(labels[i].reshape(labels[i].shape[0],1) * data, axis=0)/num_points_each_class[i]
			
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			dist = self.cluster_centers-old_centres
			if  np.max(np.linalg.norm(dist , axis=1)) < epsilon:
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

	
