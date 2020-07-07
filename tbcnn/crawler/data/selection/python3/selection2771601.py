N = int(input())
A = [int(e) for e in input().split()]

def selection_sort(A, N):
    steps = 0
    for i in range(0, N):
        minj = i
        for j in range(i, N):
            if A[minj] > A[j]:
                minj = j
        if i != minj:
            steps += 1
        A[minj], A[i] = A[i], A[minj]

    for e in A[:-1]:
        print(e, end=' ')
    print(A[-1])
    print(steps)
    return A

selection_sort(A, N)
