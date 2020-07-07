def selection_sort(A, N):
    cnt = 0
    for i in range(N):
        min_j = i
        for j in range(i, N):
            if A[j] < A[min_j]:
                min_j = j
        if i != min_j:
            A[i], A[min_j] = A[min_j], A[i]
            cnt += 1        
    return A, cnt


N = int(input().rstrip())
A = list(map(int, input().rstrip().split()))

A, cnt = selection_sort(A, N)
string = list(map(str, A))
print(' '.join(string))
print(cnt)
