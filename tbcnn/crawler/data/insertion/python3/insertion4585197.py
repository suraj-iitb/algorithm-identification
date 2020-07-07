n = int(input())
a = list(map(int, input().split()))

for x in a:
    if x == a[n-1]:
        print(x)
    else:
        print(x, end=' ')

for i in range(1, n):
    v = a[i]
    j = i - 1
    while j >= 0 and a[j] > v:
        a[j+1] = a[j]
        j -= 1
    a[j+1] = v
    for x in a:
        if x == a[n-1]:
            print(x)
        else:
            print(x, end=' ')

