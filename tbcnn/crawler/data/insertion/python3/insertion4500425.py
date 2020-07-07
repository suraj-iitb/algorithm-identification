n = int(input())
a = list(map(int,input().split()))

tmp=0
for i in range(n):
    j=i
    tmp=a[i]
    while a[j-1]>tmp and j>0:
        a[j]=a[j-1]
        j-=1
    a[j]=tmp
    print(*a)
