n = int(input())
l = list(map(int, input().split()))

print(' '.join(map(str, l)))
for i in range(1, n):
    v = l[i]
    j = i - 1
    while l[j] > v and j >= 0:
        l[j+1] = l[j]
        j -= 1
    l[j+1] = v
    print(' '.join(map(str, l)))

