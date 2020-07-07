n = int(input())
a = list(map(int, input().split()))

flag = 1
i = 0
k = 0
while flag:
    flag = 0
    for j in range(n - 1, i, -1):
        if a[j] < a[j - 1]:
            t = a[j]
            a[j] = a[j - 1]
            a[j - 1] = t
            flag = 1
            k += 1
    i += 1
for i in range(0, n-1):
    print(a[i], end=" ")
print(a[n-1])
print(k)

