def selection_sort(A, N):
    cnt = 0
    for i in range(N):
        min_index = i
        for j in range(i, N):
            if A[j] < A[min_index]:
                min_index = j
        if i != min_index:
            A[i], A[min_index] = A[min_index], A[i]
            cnt += 1
    print(' '.join(list(map(str, A))))
    print(cnt)


N = int(input())
A = list(map(int, input().split()))
selection_sort(A, N)

