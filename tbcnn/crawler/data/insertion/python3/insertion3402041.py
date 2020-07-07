n = int(input())
a = [int(i) for i in input().split()]
print(" ".join([str(i) for i in a]))

for i in range(1, n):
    j = i
    while a[j - 1] > a[j] and j > 0:
        a[j], a[j - 1] = a[j - 1], a[j]
        j -= 1
    print(" ".join([str(i) for i in a]))

