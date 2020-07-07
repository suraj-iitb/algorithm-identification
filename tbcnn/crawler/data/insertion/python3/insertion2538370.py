n = int(input())
l = list(map(int, input().split()))

for i in range(n):
    v = l[i]
    j = i - 1
    while j >= 0 and l[j] > v:
        l[j+1] = l[j]
        j -= 1
    l[j+1] = v
    print(" ".join(map(str, l)))
