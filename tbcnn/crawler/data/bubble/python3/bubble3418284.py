def swap(a, j):
    # list aのj番目の要素とj-1番目の要素を交換する関数
    k = a[j]
    a[j] = a[j-1]
    a[j-1] = k


def bubbleSort(a, n):
    sw = 0
    flag = 1
    while flag:
        flag = 0
        for j in range(n-1,0,-1):
            if a[j] < a[j-1]:
                swap(a, j)
                flag = 1
                sw += 1
    print(' '.join(list(map(str, a))))
    print(sw)

    
n = int(input())
a = list(map(int, input().split()))
bubbleSort(a, n)
