def selection_sort(A):
    count = 0
    for i in range(len(A)):
        minv = 101
        minj = -1
        for j in range(i, len(A)):
            if minv > A[j]:
                minv = A[j]
                minj = j
        if A[i] != A[minj]:
            A[i], A[minj] = A[minj], A[i]
            count += 1

    return count


n = int(input())
A = [int(x) for x in input().split()]

count = selection_sort(A)

print(' '.join([str(x) for x in A]))
print(count)
