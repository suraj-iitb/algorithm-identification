def bubbleSort(a, n):
    sw = 0
    flag = 1
    i = 0
    while (flag):
        flag = 0
        for j in range(n - 1, i, -1):
            if a[j] < a[j - 1]:
                a[j], a[j - 1] = a[j - 1], a[j]
                flag = 1
                sw += 1
        i += 1
    return sw


n = int(input())
a = list(map(int, input().split()))
sw = bubbleSort(a, n)
print(*a)
print(sw)

