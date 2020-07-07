n = int(input())
l = list(map(int, input().split()))
c = 0
for i in range(n):
    j = l[i:].index(min(l[i:])) + i
    l[i], l[j] = l[j], l[i]
    if i != j:
        c += 1
print(" ".join(map(str,l)))
print(c)
