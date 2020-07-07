#17D8103001E Fukushima Emi persimmon8 python 19.10.24

n=int(input())
A=list(map(int,input().split()))
count=0

def merge(A,left,mid,right):
    global count

    L=A[left:mid]+[10000000000000]
    R=A[mid:right]+[100000000000000]

    i=0
    j=0
    for k in range(left,right):
        count+=1
        if L[i]<=R[j]:
            A[k]=L[i]
            i=i+1
        else: 
            A[k]=R[j] 
            j=j+1

def mergeSort(a,left,right):
    if left+1<right:
         mid=(left+right)//2
         mergeSort(A,left,mid)
         mergeSort(A,mid,right)
         merge(A,left,mid,right)

mergeSort(A,0,n)
d=map(str,A)
print(' '.join(d))
print(count)

