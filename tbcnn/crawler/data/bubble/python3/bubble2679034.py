def bubbleSort(a):
    sw = 0
    for _ in range(len(a) - 1):
        for j in range(len(a) - 1, 0, -1):
            if (a[j] < a[j - 1]):
                a[j], a[j - 1] = a[j - 1], a[j]
                sw += 1
    return a, sw

n = int(input())
a = list(map(int, input().split()))

a, sw = bubbleSort(a)

print(*a)
print(sw)

