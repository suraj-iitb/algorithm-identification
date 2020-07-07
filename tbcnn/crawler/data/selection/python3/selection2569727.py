def selectionSort(A, N):
    ret = 0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        A[i], A[minj] = A[minj], A[i]
        if i != minj:
            ret += 1
    return ret


n = int(input())
a = list(map(int, input().split()))

count = selectionSort(a, n)

print(" ".join(map(str, a)))
print(count)
