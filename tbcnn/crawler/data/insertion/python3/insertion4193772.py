n = int(input())
l = list(map(int, input().split(" ")))
for i, v in enumerate(l):
    j = i - 1
    while j >= 0 and l[j] > v:
        l[j + 1] = l[j]
        j -= 1
    l[j + 1] = v
    print(*l)
