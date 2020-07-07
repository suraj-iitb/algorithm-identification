N = int(input())
A = list(map(int, input().split()))


def selectionSort(li: list, n: int):
    count = 0
    for i in range(n-1):
        minj = i
        for j in range(i+1, n):
            if li[minj] > li[j]:
                minj = j
        li[i], li[minj] = li[minj], li[i]
        if minj != i:
            count += 1
    print(*li)
    print(count)


selectionSort(A, N)

