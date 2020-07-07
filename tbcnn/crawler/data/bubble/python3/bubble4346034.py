n = int(input())
a = list(map(int, input().split()))


flag = 1
i = 0
count = 0

while flag:
    flag = 0
    for j in reversed(range(i+1, n)):
        if a[j] < a[j-1]:
            a[j], a[j-1] = a[j-1], a[j]
            flag = 1
            count += 1
    i += 1
for k in range(len(a)):
    if k == n - 1:
        print(a[k])
    else:
        print(a[k], end=' ')
print(count)

