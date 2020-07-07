import sys

n = int(input())
a = list(map(int, input().split()))

for i in range(1, n):
    print(' '.join(list(map(str, a))))
    key = a[i]
    j = i - 1
    while j >= 0 and a[j] > key:
        a[j + 1] = a[j]
        j -= 1
    a[j + 1] = key

print(' '.join(list(map(str, a))))
