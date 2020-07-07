N = int(input())
a = list(map(int, input().split()))
print(' '.join(str(x) for x in a))
for i in range(1, N):
    j = i - 1
    b = a[i]
    while j >= 0 and b < a[j]:
        a[j+1] = a[j]
        j -= 1
    a[j+1] = b
    print(' '.join(str(x) for x in a))

