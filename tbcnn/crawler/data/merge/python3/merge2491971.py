def merge(A,left,mid,right):
    global cnt
    L=A[left:mid]
    R=A[mid:right]
    L.append(float("inf"))
    R.append(float("inf"))
    i=0
    j=0
    for k in range(left, right):
        cnt+=1
        if L[i]<=R[j]:
            A[k]=L[i]
            i+=1
        else:
            A[k]=R[j]
            j+=1
            
def mergeSort(A,left,right):
        if left+1<right:
            mid=(left+right)//2
            mergeSort(A,left,mid)
            mergeSort(A,mid,right)
            merge(A,left,mid,right)   
            
n = int(input())
S=list(map(int,input().split()))
cnt=0

mergeSort(S,0,n)

print(" ".join(map(str,S)))
print(cnt)
