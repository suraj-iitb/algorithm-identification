def swap(a, i, j):
    # list aのi番目の要素とj番目の要素を交換する関数
    k = a[j]
    a[j] = a[i]
    a[i] = k


def selectionSort(a, n):
    sw = 0
    for i in range(n):
        minj = i
        for j in range(i,n):
            if a[j] < a[minj]:
                minj = j
        if i != minj:
            sw += 1
        swap(a,i,minj)
    print(' '.join(list(map(str, a))))
    print(sw)


n = int(input())
a = list(map(int, input().split()))
selectionSort(a, n)
