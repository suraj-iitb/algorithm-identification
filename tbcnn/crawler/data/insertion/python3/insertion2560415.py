n=int(input())
a=[int(i) for i in input().split()]

aaa=" ".join(map(str,a))
print(aaa)

for i in range(1,n):
    key=a[i]
    j=i-1
    while j >= 0 and a[j] > key:
        a[j+1]=a[j]
        j=j-1
    a[j+1]=key
    aaa=" ".join(map(str,a))
    print(aaa)
