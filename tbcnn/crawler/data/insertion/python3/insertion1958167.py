n = int(input())
a = input()
print(a)
a = [int(x) for x in a.split(' ')]

for i in range(1, n):
    v = a[i]
    j = i - 1
    while j >= 0 and a[j] > v:
        a[j + 1] = a[j]
        j -= 1
    a[j + 1] = v
    print(' '.join([str(x) for x in a]))
