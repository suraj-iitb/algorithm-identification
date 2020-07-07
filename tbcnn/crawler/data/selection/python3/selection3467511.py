def selectionSort(A,N):
    swapCount = 0
    for i in range(N):
        minj = A[i]
        indexj = i
        for j in range(i,N):
            if A[j] < minj:
                minj = A[j]
                indexj = j
        if indexj != i:
            A[indexj] = A[i]
            A[i] = minj
            swapCount += 1
    str = ""
    for k in range(N):
        str += "{} ".format(A[k])
    print(str[:len(str)-1])
    print(swapCount)

if __name__ == '__main__':
    N = int(input())
    A = [int(_) for _ in input().split()]

    selectionSort(A,N)

