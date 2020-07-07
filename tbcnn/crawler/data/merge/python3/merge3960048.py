import math
N=10**9 + 1
n=int(input())
a=list(map(int,input().split()))

def merge(a,left,mid,right):
    global cnt
    n=mid-left
    m=right-mid
    l=a[left:left + n]
    o=a[mid:mid + m]
    l.append(N)
    o.append(N)
    i=0
    j=0
    for k in range(left,right):
        cnt+=1
        if l[i]<=o[j]:
            a[k]=l[i]
            i+=1
        else:
            a[k]=o[j]
            j+=1

def mergesort(a,left,right):
    if left+1<right:
        mid=(left+right)//2
        mergesort(a,left,mid)
        mergesort(a,mid,right)
        merge(a,left,mid,right)





cnt=0
mergesort(a,0,len(a))
print(*a)
print(cnt)

