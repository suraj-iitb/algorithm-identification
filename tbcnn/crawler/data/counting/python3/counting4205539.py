n = int(input())
a = list(map(int, input().split()))
k = max(a) + 1

b = [0 for i in range(n)]
c = [0 for i in range(k)]

for j in range(n):
    c[a[j]] += 1

for i in range(1, k):
    c[i] += c[i-1]

for j in range(n-1, -1, -1):
    b[c[a[j]] - 1] = a[j]
    c[a[j]] -= 1

print(*b)
