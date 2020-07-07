def selectionSort(a, n):
    sw = 0
    for i in range(n):
        minj = i
        for j in range(i, n):
            if a[j] < a[minj]:
                minj = j
        a[i], a[minj] = a[minj], a[i]
        if i != minj:
            sw += 1
    return sw


n = int(input())
a = list(map(int, input().split()))

sw = selectionSort(a, n)
print(*a)
print(sw)

