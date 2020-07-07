n=int(input())
a=list(map(int,input().split()))
def InsertionSort(a,n):
    for i in range(n):
        v=a[i]
        j=i-1
        while j>=0 and v<a[j]:
            a[j+1]=a[j]
            j-=1
            a[j+1]=v
        print(*a)
InsertionSort(a,n)
