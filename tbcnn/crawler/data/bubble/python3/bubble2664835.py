n=int(input())
a=list(map(int,input().split(' ')))
sw=0
flag=False
for i in range(n):
    flag=False
    for j in range(i+1,n)[::-1]:
        if a[j]<a[j-1]:
            a[j],a[j-1]=a[j-1],a[j]
            flag=True
            sw=sw+1
    if not flag: break
print(" ".join(map(str,a)))
print(str(sw))
