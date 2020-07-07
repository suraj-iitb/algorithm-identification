n = int(input())
a = list(map(int, input().split()))

print(' '.join([str(x) for x in a]))

for i in range(1, n):

    v = a[i]
    j = i - 1
    while (j >= 0) and (a[j] > v):
        a[j+1] = a[j]
        j -= 1

    a[j+1] = v

    print(' '.join([str(x) for x in a]))

