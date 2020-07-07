def insertionSort(a):
    for i,v in enumerate(a):
        j=i-1
        while j>=0 and a[j]>v:
            a[j+1]=a[j]
            j-=1
        a[j+1]=v
        print(*a)

n = int(input())
a = list(map(int,input().split()))

insertionSort(a)
