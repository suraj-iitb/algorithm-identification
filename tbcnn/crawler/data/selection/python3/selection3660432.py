def selectionSort(A, n):
    cnt = 0
    for i in range(n):
        minj = i
        for j in range(i, n):
            if A[j] < A[minj]:
                minj = j
        if i != minj:
            A[i], A[minj] = A[minj], A[i]
            cnt += 1
    print(*A)
    print(cnt)


n = int(input())
A = list(map(int, input().split()))
selectionSort(A, n)

