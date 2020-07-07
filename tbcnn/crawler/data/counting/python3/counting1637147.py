n, a = int(input()), list(map(int, input().split()))
b, c = [0] * n, [0] * 10001

for j in range(n):
    c[a[j]] += 1

prev = -1
for i in range(10001):
    c[i] = prev = c[i] + prev

for j in range(n - 1, -1, -1):
    aj = a[j]
    b[c[aj]] = aj
    c[aj] -= 1

print(*b)
