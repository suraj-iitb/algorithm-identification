import argparse
import numpy as np
import matplotlib.pyplot as plt

np.random.seed(5927)

np.arange(5)



class KMeans():
    def __init__(self, D, n_clusters):
        self.n_clusters = n_clusters
        self.cluster_centers = np.zeros((n_clusters, D))
        
    def init_clusters(self, data):
        ### TODO
        ### Initialize cluster_centers using n_clusters points sampled from data
        
        
        self.cluster_centers = data[np.random.choice(data.shape[0],size = self.n_clusters, replace=False)]
        ### END TODO
    
    def pred(self, x):
        ### TODO: Given a sample x, return id of closest cluster center
        
        dist = np.sum((x-self.cluster_centers)**2, axis=1)
        return np.argmin(dist)
        ### END TODO
        
    
    def train(self, data, max_iter=10000, epsilon=1e-4):
        
        for it in range(max_iter):
            ### TODO
            ### Declare and initialize required variables
            
            label = [0 for i in range(data.shape[0])]
            
            classes = {}
            for i in range(self.n_clusters):
                classes[i] = []
            
            ### Update labels for each point
        
            for i in range(data.shape[0]):
                label[i] = self.pred(data[i])
                classes[label[i]].append(data[i])
            
            ### Update cluster centers
            ### Note: If some cluster is empty, do not update the cluster center
            self.old = np.copy(self.cluster_centers)
            
            for i in range(self.n_clusters):
                if(len(classes[i]) > 0):
                    self.cluster_centers[i] = np.average(classes[i], axis = 0)

            #break
            ###Check for convergence
            ### Stop if distance between each of the old and new cluster centers is less than epsilon
            c = 0
            for i in range(self.n_clusters):
                if(np.linalg.norm(self.old[i]-self.cluster_centers[i]) < epsilon):
                    c = c + 1
            
            if(c == self.n_clusters):
                break
            
            #print(it)
            ### END TODO
        return it
    
    def replace_by_center(self, data):
        out = np.zeros_like(data)
        for i, x in enumerate(data):
            out[i] = self.cluster_centers[self.pred(x)]
        return out

'''
marks = 0
data = np.array([[i+1,i*2.3] for i in range(3)])
centers = np.array([[5, 1], [-1., 2]])
op = np.array([[3.0, 4.6], [1.5, 1.15]])
kmeans = KMeans(D=2, n_clusters=2)
kmeans.cluster_centers = centers
it = kmeans.train(data, max_iter = 5)
if np.allclose(kmeans.cluster_centers, op) and it==1:
    marks += 1

#kmeans.old
kmeans.old

for i in range(4):
    print(i)
i

#kmeans.train(data, max_iter = 5)
it

marks

np.allclose(kmeans.cluster_centers, op)

'''



# +
#image = plt.imread(f'data/1.png')
#x = image.reshape(-1, 3)
#kmeans = KMeans(D=3, n_clusters=2)
#kmeans.init_clusters(x)

# +
#kmeans.cluster_centers

# +
#a = np.array([1,2,3])
#np.sum((a-kmeans.cluster_centers)**2, axis=1)
#np.argmin(dist)

# +
#np.sum((a-kmeans.cluster_centers[1])**2)
# -







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

'''
for i in range(3):
    #fig = plt.figure(figsize=(5,15))
    #c = 1
    #plt.figure()
    #fig,ax = plt.subplots(nrows=1,ncols=3, figsize=(15,5))
    #c = 0
    for k in [2,5,10]:
        image = plt.imread(f'data/' + str(i+1) + '.png')
        x = image.reshape(-1, 3)
        kmeans = KMeans(D=3, n_clusters=k)
        kmeans.init_clusters(x)
        kmeans.train(x)
        out = kmeans.replace_by_center(x)
        fig = plt.figure(figsize=(5,5))
        #fig.add_subplot(1, 3, 1)  #rows,cols,i
        plt.imshow(out.reshape(image.shape))
        plt.title(str(i+1) + '.png for k=' + str(k) + '{ignore axes}')
        fig.savefig('plots/q3_image' + str(i+1) + 'K=' + str(k) +'.pdf')
        plt.show()
        #ax[c].imshow(out.reshape(image.shape))
        #c = c+1
        #c = c+1
    #plt.tight_layout()
    #plt.title(str(i) + '.png for k = 2,5,10 [Left to Right] {ignore axes}')
    
'''







