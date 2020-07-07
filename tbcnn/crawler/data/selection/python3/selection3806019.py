N = int(input())
A = [int(x) for x in input().split()]

def SelectionSort(A):
    N = len(A)
    count = 0
    for i in range(N):
        minj = i
        for j in range(i,N):
            if A[j] < A[minj]:
                minj = j
        if i != minj:
            A[i], A[minj] = A[minj], A[i]
            count += 1
    for k in range(N-1):
        print(A[k], end=" ")
    print(A[N-1])
    print(count)

SelectionSort(A)

