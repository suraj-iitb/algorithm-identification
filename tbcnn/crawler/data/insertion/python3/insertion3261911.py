n = int(input().strip())
a = [int(s) for s in input().strip().split(' ')]
for i in range(1, n):
    print(' '.join((str(i) for i in a)))
    v = a[i]
    j = i - 1
    while j >= 0 and a[j] > v:
        a[j+1] = a[j]
        j -= 1
    a[j+1] = v

print(' '.join((str(i) for i in a)))
