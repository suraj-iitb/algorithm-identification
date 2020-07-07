N = int(input())
A = list(map(int, input().split()))

def selectionSort(A, N):
    counter = 0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        if i != minj:
            counter += 1
        A[i], A[minj] = A[minj], A[i]
        i += 1

    print(" ".join(map(str, A)), counter, sep="\n")
selectionSort(A, N)
