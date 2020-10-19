from sklearn import svm
from sklearn.model_selection import train_test_split
import numpy as np
from sklearn.model_selection import GridSearchCV
from sklearn import metrics

parameters = {'kernel':('linear', 'rbf'), 'C':[1, 100]}

X = []
y = []

with open('../Results/all/100/100_svm_feature_vector.csv') as vectors:

    for vector in vectors:

        vector = vector.strip()

        if vector != '':

            comps = vector.split(',')

            if comps[0].startswith('b'):
                y.append(0)
            elif comps[0].startswith('i'):
                y.append(1)
            elif comps[0].startswith('s'):
                y.append(2)
            elif comps[0].startswith('c'):
                y.append(3)
            elif comps[0].startswith('m'):
                y.append(4)
            elif comps[0].startswith('q'):
                y.append(5)
            
            temp = []
            for comp in comps[1:]:
                temp.append(int(comp))
            X.append(temp)

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.20, random_state=20)

svc = svm.SVC(decision_function_shape='ovo')
clf = GridSearchCV(svc, parameters)
clf.fit(X_train, y_train)

y_h_test = clf.predict(X_test)

# print('1: Bubble\n2: Insertion\n')
print(y_h_test)
print(np.array(y_test))

with open('../Results/all/100/metrics-r3.txt', 'w') as op:
    # Print the confusion matrix
    op.write(str(metrics.confusion_matrix(y_test, y_h_test)))

    # Print the precision and recall, among other metrics
    op.write(str(metrics.classification_report(y_test, y_h_test, digits=2)))

# tp = 0
# fp = 0
# tn = 0
# fn = 0
# for index in range(len(y_test)):
#     if(y_test[index] == 1):
#         if(y_h_test[index] == 1):
#             tp += 1
#         else:
#             fn += 1
#     if(y_test[index] == 0):
#         if(y_h_test[index] == 0):
#             tn += 1
#         else:
#             fp += 1

# recall = tp / (tp +fn) * 100
# precision = tp / (tp +fp) * 100
# try:
#     f1 = 2*((precision*recall)/(precision+recall))
# except Exception:
#     f1 = 0.0

# print('\n===========================SVM========================================')
# print('Recall for hypothesis SVM is: ', str(round(recall,2)) + ' %')
# print('Precision for hypothesis SVM is: ', str(round(precision,2)) + ' %')
# print('F1 Score for hypothesis SVM is: ', str(round(f1,2)) + ' %')
# print('======================================================================')

# # print(clf.cv_results_)

