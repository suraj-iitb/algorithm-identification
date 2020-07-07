n = int(input())
a = list(map(int,input().split()))
flag = 1
cnt = 0
while flag:
    flag = 0
    i = -1
    for j in range(n-1, i+1, -1):
        if a[j] < a[j-1]:
            a[j], a[j-1] = a[j-1], a[j]
            cnt += 1
            flag = 1
    i += 1
print(' '.join(map(str, a)))
print(cnt)
