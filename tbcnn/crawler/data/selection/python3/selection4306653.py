def selectionSort(A, N):
    cnt = 0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        if i != minj:
           cnt += 1
           tmp = A[i]
           A[i] = A[minj]
           A[minj] = tmp
    print(*A)
    print(cnt)
    
n = int(input())
a = list(map(int, input().split()))

selectionSort(a, n)
