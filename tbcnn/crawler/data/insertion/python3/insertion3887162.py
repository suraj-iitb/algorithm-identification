n=int(input())
a=[int(i) for i in input().split()]
#print(" ".join(list(map(str,a))))
for i in range(n):
    x=a[i]
    for j in range(i):
        if a[i-j-1]>a[i-j]:
            a[i-j-1],a[i-j]=a[i-j],a[i-j-1]
        else:
            break
    print(" ".join(list(map(str,a))))

