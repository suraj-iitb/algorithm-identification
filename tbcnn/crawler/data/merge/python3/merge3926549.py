def merge(A,l,m,r):
    L=A[l:m];R=A[m:r]
    L.append(INF);R.append(INF)
    global cnt

    i=j=0    
    for k in range(l,r):
        cnt+=1
        if L[i]<=R[j]:
            A[k]=L[i]
            i+=1
        else:
            A[k]=R[j]
            j+=1        

def mergeSort(A,l,r):
    if l+1==r:
        pass
    else:
        m=(l+r)//2
        mergeSort(A,l,m)
        mergeSort(A,m,r)
        merge(A,l,m,r)

INF=10**9+1
n=int(input())
S=list(map(int,input().split()))
cnt=0

mergeSort(S,0,n)

for i in range(n):
    if i<n-1:
        print(S[i],end=' ')
    else:
        print(S[i])
print(cnt)
