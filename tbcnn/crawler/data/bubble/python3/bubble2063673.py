n = int(input())
L = list(map(int, input().split()))
p = 0
for _ in L:
    for j in range(n-1, 0, -1):
        if L[j] < L[j-1]:
            L[j], L[j-1] = L[j-1], L[j]
            p += 1
print(*L)
print(p)
