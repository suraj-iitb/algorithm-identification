n = int(input())
a = [int(i) for i in input().split()]
flag = False
cnt = 0
for i in range(n-1):
    if flag: break
    flag = True
    for j in range(n-1,i,-1):
        if a[j] < a[j-1]:
            a[j],a[j-1] = a[j-1],a[j]
            cnt += 1
            flag = False
print(" ".join(map(str,a)))
print(cnt)
