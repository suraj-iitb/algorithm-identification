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
		cho=np.random.choice(range(np.shape(data)[0]), self.n_clusters, replace=False)
		self.cluster_centers=data[cho,:]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		tmp=np.sum((self.cluster_centers-x)**2,axis=1)
		return np.argmin(tmp)
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		def gaussian_kernel(X,Y):
			sigma=1
			xx=np.sum(X**2,axis=1)/(-2*sigma*sigma)
			yy=np.sum(Y**2,axis=1)/(-2*sigma*sigma)
			xy=np.matmul(X,np.transpose(Y))/(sigma*sigma)
			xy=xy+yy
			xy=np.transpose(np.transpose(xy)+xx)
			return np.exp(xy)
		for it in range(max_iter):
			# if it%100==0:
			# 	print(it)
			### TODO
			### Declare and initialize required variables
			new_cents=np.zeros((self.n_clusters,np.shape(data)[1]))
			new_counts=np.zeros(self.n_clusters)
			### Update labels for each point
			# for i in range(np.shape(data)[0]):
			# 	tmp=self.pred(data[i])
			# 	new_cents[tmp]=new_cents[tmp]+data[i]
			# 	new_counts[tmp]=new_counts[tmp]+1
			# dists=np.sqrt(((np.transpose(data) - np.transpose(self.cluster_centers)[:,np.newaxis])**2).sum(axis=2))
			labels= gaussian_kernel(data,self.cluster_centers)
			labels=np.argmax(labels,axis=1)
			# print(labels[:100])
			# print(labels.shape)
			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			# new_cents[new_counts!=0]=np.transpose(np.transpose(new_cents[new_counts!=0])/new_counts[new_counts!=0])
			# new_cents[new_counts==0]=self.cluster_centers[new_counts==0]
			new_cents=np.copy(self.cluster_centers)
			
			for i in range(self.n_clusters):
				if np.sum(labels==i)>0:
					new_cents[i]=np.squeeze(np.sum(data[labels==i,:],axis=0)/np.sum(labels==i))
			# print(new_cents)
			# print(self.cluster_centers)
			# print(new_cents-self.cluster_centers)
			# print(np.sqrt(np.sum((new_cents-self.cluster_centers)**2,axis=1)))
			### Check for convergence
			cond=np.sqrt(np.sum((new_cents-self.cluster_centers)**2,axis=1))<epsilon

			### Stop if distance between each of the old and new cluster centers is less than epsilon
			if np.all(cond):
				break
			self.cluster_centers=np.copy(new_cents)
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
	# print(x.shape)
	kmeans = KMeans(D=3, n_clusters=args.k)
	kmeans.init_clusters(x)
	kmeans.train(x)
	out = kmeans.replace_by_center(x)
	plt.imshow(out.reshape(image.shape))
	plt.show()
	# for i in ['1', '2', '3']:
	# 	for k in [2,5,10]:
	# 		print(i+str(k))
	# 		image = plt.imread(f'data/'+i+'.png')
	# 		x = image.reshape(-1, 3)
	# 		# print(x.shape)
	# 		kmeans = KMeans(D=3, n_clusters=k)
	# 		kmeans.init_clusters(x)
	# 		kmeans.train(x)
	# 		out = kmeans.replace_by_center(x)
	# 		plt.imshow(out.reshape(image.shape))
	# 		plt.savefig(i+'k='+str(k)+'.png')

