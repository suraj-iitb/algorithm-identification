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
		n=data.shape[0]
		d=data.shape[1]
		ll=np.random.choice(range(n),self.n_clusters)
		ll=data[ll]
		ll=np.array(ll).reshape((self.n_clusters,d))
		self.cluster_centers=ll
		pass
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		min_ind=-1
		min_val=float("inf")
		ll=self.cluster_centers
		for i in range(len(ll)):
			center=ll[i]
			norm=np.linalg.norm(x-center)
			if norm<min_val:
				min_val=norm
				min_ind=i
		return min_ind
		pass
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			labelDict={}
			end=True
			numClusters=self.n_clusters
			clusters=self.cluster_centers
			oldC=clusters.copy()
			newC=np.zeros((numClusters,data.shape[1]))
			nums=np.zeros((numClusters,1))
			pass
			### Update labels for each point
			for i in range(data.shape[0]):
				index=i
				point=data[i]
				label=self.pred(point)
				labelDict[index]=label
				
			### Update cluster centers
			for p in range(data.shape[0]):
				label=labelDict[p]
				# print(newC[p])
				newC[label]+=data[p]
				# print(newC[p])
				nums[label]+=1
			for i in range(numClusters):
				if nums[i]!=0:
					clusters[i]=newC[i]/nums[i]
					
			
			### Note: If some cluster is empty, do not update the cluster center
			# print(clusters,oldC)

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			for i in range(numClusters):
				# print(i,np.linalg.norm(clusters[i]-oldC[i]),epsilon,sep=' ')
				if np.linalg.norm(clusters[i]-oldC[i])>=epsilon:
					end=False
					break
			if end:
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

