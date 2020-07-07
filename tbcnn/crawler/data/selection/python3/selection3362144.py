def selectionSort(a, n):
    count = 0
    for i in range(n):
        minj = i
        for j in range(i, n):
            if a[j] < a[minj]:
                minj = j
        a[i], a[minj] = a[minj], a[i]
        if i != minj: count += 1
    printArray(a)
    print(count)


#配列の出力
def printArray(array):
    print(' '.join(map(str, array)))

###----------mainここから---------------

#配列の要素数と要素の入力
n = int(input())
a = list(map(int, input().split()))

selectionSort(a, n)
