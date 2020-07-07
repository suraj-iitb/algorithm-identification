n, *aa = map(int, open(0).read().split())

for i in range(n):
    j = i
    while j-1 >= 0:
        if aa[j-1] > aa[j]:
            aa[j-1], aa[j] = aa[j], aa[j-1]
        j -= 1
    print(*aa)
