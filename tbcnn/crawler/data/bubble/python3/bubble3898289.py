N = int(input())
A = list(map(int, input().split()))


def bubbleSort(li: list, n: int):
    count = 0
    for i in range(n-1):
        for j in reversed(range(i+1, n)):
            if li[j-1] > li[j]:
                li[j-1], li[j] = li[j], li[j-1]
                count += 1
    print(*li)
    print(count)


bubbleSort(A, N)

