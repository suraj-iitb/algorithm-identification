from operator import itemgetter 
def partition(A,p,r):
    x = A[r][1]
    i = p-1
    for j in range(p,r):
        if A[j][1] <= x:
            i += 1
            A[i],A[j] = A[j],A[i]
    A[i+1],A[r] = A[r],A[i+1]
    return i+1

def quicksort(A,p,r):
    if p < r:
        q = partition(A,p,r)
        quicksort(A,p,q-1)
        quicksort(A,q+1,r)
A = []
n = int(input())
for i in range(n):
    a,b = map(str,input().split())
    A.append([a,int(b)])

B = [i for i in A]
quicksort(A,0,n-1)

B.sort(key=itemgetter(1))

if A == B:
    print("Stable")
else:
    print("Not stable")
for i in A:
    print(i[0],i[1])
