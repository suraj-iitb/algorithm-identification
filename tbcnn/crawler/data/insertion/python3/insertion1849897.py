import string
n = int(input())
l = []
l = list(map(int, input().split()))
for i in range(n):
    key = l[i]
    j = i -1
    while j >= 0 and l[j] > key:
        l[j + 1] = l[j]
        j -= 1
    l[j + 1] = key
    print(' '.join(map(str, l)))
