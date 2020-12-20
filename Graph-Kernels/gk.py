#!/usr/bin/env python
# coding: utf-8

# In[1]:


# Network-x imports
from networkx.readwrite.graphml import read_graphml
import networkx as nx

# Graph Kernels import
from grakel.utils import graph_from_networkx
from grakel.kernels import WeisfeilerLehman, VertexHistogram, ShortestPath, RandomWalk, SubgraphMatching, NeighborhoodHash, GraphletSampling, PyramidMatch, SvmTheta

# SVM imports
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score
from sklearn.model_selection import train_test_split
from sklearn import metrics

# general imports
import os


# # Data Preprocessing

# ## Data Loading

# In[2]:


graphs = list()
labels = list()
tags = {'Bubble': 0, 'Insertion': 1, 'Selection': 2, 'Counting': 3, 'Merge': 4, 'Quick': 5}

for algo in os.listdir('CFG'):
    count = 1
    for file in os.listdir('CFG/'+algo):
        graphs.append(read_graphml('CFG/'+algo+'/'+file))
        labels.append(tags[algo])
        if(count == 700):
            break
        count += 1


# In[3]:


# len(graphs), len(labels)


# In[4]:


# nx.draw_networkx(graphs[0])


# In[5]:


G_train, G_test, Y_train, Y_test = train_test_split(graphs, labels, test_size=0.20, random_state=42)
# len(G_train), len(G_test), len(Y_train), len(Y_test)


# ## Convert Network-X Graph to Adj List Representation of GraKel

# In[6]:


G_train = list(graph_from_networkx(G_train, node_labels_tag='label'))
G_test = list(graph_from_networkx(G_test, node_labels_tag='label'))

# In[7]:


# G_train[0]


# # Kernel Computation & SVM

# ## 1. Compute the Weisfeiler Lehman Kernel

# In[8]:


# Initialize a Weisfeiler-Lehman subtree kernel
gk = WeisfeilerLehman()


# In[9]:


# Construct kernel matrices
K_train = gk.fit_transform(G_train)
K_test = gk.transform(G_test)

with open('km_train.txt', 'w') as f:
    for i in K_train:
        for j in i:
            f.write(str(j)+' ')
        f.write('\n')
# with open('km_test.txt', 'w') as f:
#     f.write(str(K_test))

# In[10]:


# Train an SVM classifier
clf = SVC(kernel='precomputed')
clf.fit(K_train, Y_train) 


# In[11]:


# Test classifier
Y_pred = clf.predict(K_test)


# In[12]:


# Evaluate the predictions
print("Accuracy:", accuracy_score(Y_test, Y_pred))


# In[14]:


print(metrics.confusion_matrix(Y_test, Y_pred))

# Print the precision and recall, among other metrics
print(metrics.classification_report(Y_test, Y_pred, digits=2))


# In[16]:


print(K_test)


# # ## 2. The random walk kernel class (Time Consuming)

# # In[17]:


# gk = RandomWalk()


# # In[ ]:


# # Construct kernel matrices
# K_train = gk.fit_transform(G_train)
# K_test = gk.transform(G_test)


# # In[76]:


# # Train an SVM classifier
# clf = SVC(kernel='precomputed')
# clf.fit(K_train, Y_train) 


# # In[77]:


# # Test classifier
# Y_pred = clf.predict(K_test)


# # In[78]:


# print(metrics.confusion_matrix(Y_test, Y_pred))

# # Print the precision and recall, among other metrics
# print(metrics.classification_report(Y_test, Y_pred, digits=2))


# # ## 3. Subgraph Matching

# # In[84]:


# gk = SubgraphMatching(ke=None)


# # In[85]:


# # Construct kernel matrices
# K_train = gk.fit_transform(G_train)
# K_test = gk.transform(G_test)


# # In[86]:


# # Train an SVM classifier
# clf = SVC(kernel='precomputed')
# clf.fit(K_train, Y_train) 


# # In[87]:


# # Test classifier
# Y_pred = clf.predict(K_test)


# # In[88]:


# print(metrics.confusion_matrix(Y_test, Y_pred))

# # Print the precision and recall, among other metrics
# print(metrics.classification_report(Y_test, Y_pred, digits=2))


# # ## 4. NeighborhoodHash Kernel

# # In[90]:


# gk = NeighborhoodHash()


# # In[91]:


# # Construct kernel matrices
# K_train = gk.fit_transform(G_train)
# K_test = gk.transform(G_test)


# # In[92]:


# # Train an SVM classifier
# clf = SVC(kernel='precomputed')
# clf.fit(K_train, Y_train) 


# # In[93]:


# # Test classifier
# Y_pred = clf.predict(K_test)


# # In[94]:


# print(metrics.confusion_matrix(Y_test, Y_pred))

# # Print the precision and recall, among other metrics
# print(metrics.classification_report(Y_test, Y_pred, digits=2))


# # ## 5.  GraphletSampling Kernel

# # In[97]:


# gk = GraphletSampling()


# # In[98]:


# # Construct kernel matrices
# K_train = gk.fit_transform(G_train)
# K_test = gk.transform(G_test)


# # In[99]:


# # Train an SVM classifier
# clf = SVC(kernel='precomputed')
# clf.fit(K_train, Y_train) 


# # In[100]:


# # Test classifier
# Y_pred = clf.predict(K_test)


# # In[101]:


# print(metrics.confusion_matrix(Y_test, Y_pred))

# # Print the precision and recall, among other metrics
# print(metrics.classification_report(Y_test, Y_pred, digits=2))


# # ## 6. SvmTheta Match

# # In[111]:


# gk = SvmTheta()


# # In[ ]:


# # Construct kernel matrices
# K_train = gk.fit_transform(G_train)
# K_test = gk.transform(G_test)


# # In[ ]:


# # Train an SVM classifier
# clf = SVC(kernel='precomputed')
# clf.fit(K_train, Y_train) 

