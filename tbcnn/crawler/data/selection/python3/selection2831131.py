n = int(input())
a = list(map(int, input().split()))

ans = 0
for i in range(n-1):
    mi = i
    for j in range(i, n):
        if a[j] < a[mi]:
            mi = j
    if mi != i:
        a[i], a[mi] = a[mi], a[i]
        ans += 1
print(' '.join(map(str, a)))
print(ans)
