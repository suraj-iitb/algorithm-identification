n = int(input())
a = list(map(int, input().split()))
co = 0

for i in range(n):
    minv = a[i]
    mink = i
    for j in range(i, n):
        if a[j] < minv:
            minv = a[j]
            mink = j
    if a[i] != minv:
        a[i], a[mink] = a[mink], a[i]
        co += 1

print(*a)
print(co)
