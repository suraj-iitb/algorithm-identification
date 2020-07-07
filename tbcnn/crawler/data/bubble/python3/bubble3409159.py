n = int(input())
a = list(map(int, input().split()))
i = 0
cnt = 0
flag = 1
while flag:
    flag = 0
    for j in range(n - 1, i, -1):
        if a[j] < a[j - 1]:
            flag = 1
            cnt += 1
            a[j], a[j - 1] = a[j - 1], a[j]
    i += 1
print(" ".join(map(str, a)))
print(cnt)
