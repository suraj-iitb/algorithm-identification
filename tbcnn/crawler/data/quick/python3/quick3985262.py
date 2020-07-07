import copy


def partition(A,p,r):
    x=A[r]
    i=p-1
    for j in range(p,r):
        if A[j][1]<=x[1]:
            i +=1
            A[i],A[j]=A[j],A[i]
    A[i+1],A[r]=A[r],A[i+1]
    return i+1


def quickSort(A,p,r):
    if p<r:
        q=partition(A,p,r)
        quickSort(A,p,q-1)
        quickSort(A,q+1,r)


n=int(input())
data=[]
for i in range(n):
    mark,num=map(str,input().split())
    data.append([mark,int(num)])

data_copy=copy.deepcopy(data)
data_copy=sorted(data_copy, key=lambda x:x[1])

quickSort(data,0,n-1)

print("Stable" if data==data_copy else "Not stable")

for mark,num in data:print(mark,num)
