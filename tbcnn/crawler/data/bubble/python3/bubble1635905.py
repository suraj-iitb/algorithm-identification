n, a, f, c = int(input()), list(map(int, input().split())), True, 0

while f:
    f = False
    for j in range(n - 1, 0, -1):
        if a[j] < a[j - 1]:
            a[j], a[j - 1], c = a[j - 1], a[j], c + 1
            f = True

print(*a)
print(c)
