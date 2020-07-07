n = int(input())
a = list(map(int, input().split()))

ans = 0
for i in range(n):
    for j in reversed(range(i+1, n)):
        if a[j] < a[j - 1]:
            a[j], a[j - 1] = a[j - 1], a[j]
            ans += 1
print(' '.join(map(str, a)))
print(ans)
