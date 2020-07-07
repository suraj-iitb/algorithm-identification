N = int(input())
A = list(map(int, input().split()))


def insertionSort(li: list, n: int):
    for i in range(n):
        v = li[i]
        j = i - 1
        while 0 <= j and v < li[j]:
            li[j+1] = li[j]
            j -= 1
        li[j+1] = v
        print(*li)


insertionSort(A, N)

