def selection_sort(A, N):
    change_cnt = 0
    for i in range(0, N-1):
        min_idx = i
        for j in range(i+1, N):
            if A[j] < A[min_idx]:
                min_idx = j
        A[i], A[min_idx] = A[min_idx], A[i]
        if i != min_idx:
            change_cnt += 1
    print(" ".join([str(a) for a in A]))
    print(change_cnt)
N = int(input().rstrip())
A = [int(a) for a in input().rstrip().split(" ")]
selection_sort(A, N)
