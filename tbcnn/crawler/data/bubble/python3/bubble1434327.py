n = int(input())
a = list(map(int, input().split()))
count = 0
flag = True

while flag:
    flag = False
    for j in range(n - 1, 0, -1):
        if a[j] < a[j - 1]:
            a[j], a[j - 1] = a[j - 1], a[j]
            count += 1
            flag = True

print(*a)
print(count)
