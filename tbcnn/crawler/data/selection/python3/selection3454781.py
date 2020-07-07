def selection_sort(A, N):
    count = 0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        if i != minj:
            A[i], A[minj] = A[minj], A[i]
            count += 1
    return count


N = int(input())
A = list(map(int, input().split()))
count = selection_sort(A, N)

print(" ".join(list(map(str, A))))
print(count)

