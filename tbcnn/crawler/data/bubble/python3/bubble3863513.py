n = int(input())
a = [int(i) for i in input().split()]

cnt = 0
for i in range(n - 1):
    last = n - i - 1
    for j in range(last):
        if a[j] > a[j + 1]:
            a[j], a[j + 1] = a[j + 1], a[j]
            cnt += 1
print(' '.join(map(str, a)))
print(cnt)


