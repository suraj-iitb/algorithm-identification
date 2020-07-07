N = int(input())
A = [int(item) for item in input().split()]

def selectionSort(A, N):
    cnt = 0
    for i in range(N-1):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        if i != minj:
            A[i], A[minj] = A[minj], A[i]
            cnt += 1
    
    print(*A)
    print(cnt)

selectionSort(A, N)
