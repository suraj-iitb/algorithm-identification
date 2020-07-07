N = int(input())
A = [int(i) for i in input().split()]

def selectionSort(A):
    count = 0
    for i in range(len(A)):
        minj = i
        for j in range(i, len(A)):
            if A[j] < A[minj]:
                minj = j
        if i != minj:
            tmp = A[i]
            A[i] = A[minj]
            A[minj] = tmp
            count += 1
    return A, count

A ,count = selectionSort(A)
print(' '.join([str(i) for i in A]))
print(count)
