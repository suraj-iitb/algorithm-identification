def selectionSort(A, N):
    count = 0
    for i in range(N-1):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        if i != minj:
            temp = A[i]
            A[i] = A[minj]
            A[minj] = temp
            count += 1
    return count

N = int(input())
A = list(map(int, input().split()))
c = selectionSort(A, N)
print(" ".join(map(str, A)))
print(c)

