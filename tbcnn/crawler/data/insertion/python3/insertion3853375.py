N = int(input())
a = [int(i) for i in input().split()]
print(' '.join(map(str, a)))
for i in range(1, N):
    v = a[i]
    j = i - 1
    while j >= 0:
        if a[j] > v:
            a[j + 1], a[j] = a[j], a[j - 1]
            j -= 1
        else:
            break
    a[j + 1] = v
    print(' '.join(map(str, a)))

