from sklearn import svm
from sklearn.model_selection import train_test_split
import numpy as np
from sklearn.model_selection import GridSearchCV

parameters = {'kernel':('linear', 'rbf'), 'C':[1, 100]}

X =[]
y = []

with open('vector.txt') as vectors:

    for vector in vectors:

        vector = vector.strip()

        if vector != '':

            comps = vector.split(',')

            if comps[0].startswith('b'):
                y.append(1)
            else:
                y.append(0)
            
            temp = []
            for comp in comps[1:]:
                temp.append(int(comp))
            X.append(temp)

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.20, random_state=20)

svc = svm.SVC()
clf = GridSearchCV(svc, parameters)
clf.fit(X_train, y_train)

y_h_test = clf.predict(X_test)

print(y_h_test)
print(np.array(y_test))

accuracy = (y_h_test.size - np.sum(np.absolute(np.subtract(y_h_test, y_test)))) / y_h_test.size

print("Accuracy:", accuracy)

# print(clf.cv_results_)

