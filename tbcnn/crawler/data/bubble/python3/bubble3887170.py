#バブルソート
n=int(input())
a=[int(i) for i in input().split()]

f=1 #隣接した要素が昇順になっていないものが存在する
j=0
while f:
    f=0
    for i in range(n-1):
        if a[n-i-1]<a[n-i-2]:
            a[n-i-1],a[n-i-2]=a[n-i-2],a[n-i-1]
            f=1
            j+=1
print(" ".join(list(map(str,a))))
print(j)

