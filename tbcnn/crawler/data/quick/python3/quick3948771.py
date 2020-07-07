def partition(A,p,r):
    x=A[r][1]
    i=p-1
    for j in range(p,r):
        if A[j][1]<=x:
            i+=1
            m=A[i]
            A[i]=A[j]
            A[j]=m
    m=A[i+1]
    A[i+1]=A[r]
    A[r]=m
    return i+1
def quicksort(A,p,r):
    if p<r:
        q=partition(A,p,r)
        quicksort(A,p,q-1)
        quicksort(A,q+1,r)
n=int(input())
A=[]
for _ in range(n):
    card=input().split()
    A.append([card[0],int(card[1])])
Acopy=A.copy()
quicksort(A,0,n-1)
ans="Stable"
for i in range(n-1):
    if A[i][1]==A[i+1][1]:
        if Acopy.index(A[i+1])<Acopy.index(A[i]):
            ans="Not stable"
            break
print(ans)
for i in range(n):
    print(*A[i])
