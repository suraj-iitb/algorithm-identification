n = int(input())
a = list(map(int,input().split()))
flag = True
ret = 0
while flag:
    flag=False
    for j in range(1,n)[::-1]:
        if a[j-1] > a[j]:
            a[j],a[j-1]=a[j-1],a[j]
            flag=True
            ret += 1
print(" ".join(map(str,a)))
print(ret)

