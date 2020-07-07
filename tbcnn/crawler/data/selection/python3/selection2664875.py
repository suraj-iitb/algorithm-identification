n=int(input())
a=list(map(int,input().split(' ')))
sw=0
for i in range(n-1):
    minj=i
    for j in range(i,n):
        if a[j]<a[minj]:
            minj=j
    a[i],a[minj]=a[minj],a[i]
    if i != minj:
        sw=sw+1
print(" ".join(map(str,a)))
print(str(sw))
