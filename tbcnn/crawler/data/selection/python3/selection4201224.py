n = int(input())
l = list(map(int, input().split(" ")))
f = 0
for j in range(n-1):
    m = l[j:].index(min(l[j:]))
    if m != 0:
        l[j], l[m + j] = l[m + j], l[j]
        f += 1
print(*l)
print(f)
