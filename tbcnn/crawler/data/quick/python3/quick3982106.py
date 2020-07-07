import copy

def partition(A,p,r):
    x=A[r-1]
    i=p-1
    for j in range(p-1,r-1):
        if int(A[j][1])<=int(x[1]):
            A_j=A[j]
            A[j]=A[i]
            A[i]=A_j
            i+=1
    A[r-1]=A[i]
    A[i]=x
    return i

def quicksort(A,p,r):
    if p<r:
        q=partition(A,p,r)
        quicksort(A,p,q)
        quicksort(A,q+1,r)

 
n=int(input())
a=[]
for i in range(n):
    a.append(input().split())
    
b=copy.deepcopy(a)
quicksort(b,1,n)
flag=True
for j in range(n-1):
    if int(b[j][1]) == int(b[j+1][1]): 
        if a.index(b[j]) > a.index(b[j+1]):flag=False ;break
if flag:print('Stable')
else:print('Not stable')

for i in b:
    print(*i)
