# 1_1_A_InsertionSort.py

n = int(input())
a = [int(x) for x in input().split()]

print(' '.join([str(x) for x in a]))
for i in range(1, len(a)):
    for j in range(i, 0, -1):
        if a[j] < a[j-1]:
            a[j], a[j-1] = a[j-1], a[j]
    print(' '.join([str(x) for x in a]))

