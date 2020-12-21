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
		m=data.shape[0]
		size=m//(self.n_clusters)
		base=size//2
		for i in range(self.n_clusters):
			self.cluster_centers[i,:]=data[base+size*i,:]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		val=np.linalg.norm(x-self.cluster_centers[0],2)
		closest_center=0
		for i in range(1,self.n_clusters):
			temp=np.linalg.norm(x-self.cluster_centers[i],2)
			if(temp<val):
				val=temp
				closest_center=i
		return closest_center
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			# print(it)
			m=data.shape[0]
			D=data.shape[1]
			n=self.n_clusters
			data_clusters=np.ones(m)
			data_clusters=-1*data_clusters # stores the index of the cluster to which data[i] belongs
			cluster_point_cnt=np.zeros(n) # stores the number of points in each cluster

			### Update labels for each point
			# for i in range(m):
			# 	closest_cluster_id=self.pred(data[i])
			# 	data_clusters[i]=closest_cluster_id
			# 	cluster_point_cnt[closest_cluster_id]+=1
			X=data
			Y=self.cluster_centers
			G=np.matmul(X,np.transpose(Y))
			G=-2*G # G= -2*||x.y|| -> m x n_clusters
			B=np.square(Y)
			l=np.ones(D)
			B=np.matmul(B,l)
			G=G+B # G = -2*||x.y|| + ||y||^2 -> m x n_clusters
			C=np.square(X)
			C=np.matmul(C,l)
			G=np.transpose(G)+C
			G=np.transpose(G) # G = -2*||x.y|| + ||y||^2 + ||x||^2 -> m x n_clusters

			data_clusters=np.argmin(G,axis=1)
			for j in range(n):
				cluster_point_cnt[j]=np.count_nonzero(data_clusters==j)
			# update count

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			old_cc=self.cluster_centers
			new_cc=np.zeros((n, D))
			# for i in range(m):
			# 	cluster_id=data_clusters[i]
			# 	# print(cluster_id)
			# 	new_cc[int(cluster_id)]+=data[i]
			for j in range(n):
				new_cc[j]=np.sum(data[data_clusters==j],axis=0)

			for j in range(n):
				if(cluster_point_cnt[j]==0):
					new_cc[j]=old_cc[j]
				else:
					new_cc[j]=new_cc[j]/cluster_point_cnt[j]

			self.cluster_centers=new_cc

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			stop=1
			for i in range(n):
				val=np.linalg.norm(old_cc[i]-new_cc[i],2)
				# print(val)
				if(val>=epsilon):
					stop=0
					break

			if(stop==1):
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
	plt.title("Image"+str(args.image)+" : k="+str(args.k))
	plt.imshow(out.reshape(image.shape))
	plt.show()

