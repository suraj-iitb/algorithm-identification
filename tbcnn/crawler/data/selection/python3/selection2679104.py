def selectionSort(a):
    sw = 0
    for i in range(len(a)):
        minj = i
        for j in range(i, len(a)):
            if a[j] < a[minj]:
                minj = j
        a[i], a[minj] = a[minj], a[i]
        if i != minj:
            sw += 1
    return a, sw

N = int(input())
A = list(map(int, input().split()))

A, sw = selectionSort(A)

print(*A)
print(sw)
