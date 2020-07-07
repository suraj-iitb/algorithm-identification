n = int(input())
a = list(map(int, input().split()))
count = 0

for i in range(n-1):
    for j in range(n-1, i, -1):
        if a[j-1] > a[j]:
            a[j-1], a[j] = a[j], a[j-1]
            count += 1

print(*a)
print(count)
