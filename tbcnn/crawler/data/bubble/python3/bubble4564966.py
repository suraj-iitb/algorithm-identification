def printList(array):
    print(' '.join(map(str, array)))

def bubbleSort(A, N):
    needToContinue = True
    swapCount = 0
    while needToContinue:
        needToContinue = False
        for index in range(N - 1, 0, -1):
            if A[index] < A[index - 1]:
                A[index], A[index - 1] = A[index - 1], A[index]
                swapCount += 1
                needToContinue = True
    printList(A)
    print(str(swapCount))


if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split()))
    bubbleSort(A, N)
