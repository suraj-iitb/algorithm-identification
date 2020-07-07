n = int(input())
a = list(map(int, input().split()))
MAXAI = 10000

b = [0] * n
c = [0] * (MAXAI + 1)
for i in range(n):
    c[a[i]] += 1
for i in range(1, MAXAI + 1):
    c[i] += c[i-1]
for j in range(n-1, -1, -1):
    b[c[a[j]]-1] = a[j]
    c[a[j]] -= 1

print(' '.join(map(str, b)))

