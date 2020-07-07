def selectionSort(A):
    N = len(A)
    cnt = 0
    for i in range(N):
        min_i = i
        for j in range(i,N):
            if A[j] < A[min_i]:
                min_i = j
        if min_i != i:
            A[i], A[min_i] = A[min_i], A[i]
            cnt += 1
    print(*A)
    print(cnt)

N=int(input())
A=list(map(int, input().split()))
selectionSort(A)
