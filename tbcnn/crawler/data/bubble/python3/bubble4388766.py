n = int(input())
a = list(map(int,input().split()))
flag = 1
cnt = 0
while flag:
    flag = 0
    for j in range(n-1,0,-1):
        if a[j] < a[j-1]:
            cnt += 1
            a[j],a[j-1] = a[j-1],a[j]
            flag = 1
print(*a)
print(cnt)
