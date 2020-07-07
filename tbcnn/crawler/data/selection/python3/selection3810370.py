def SelectionSort(A):
    cnt = 0
    for i in range(len(A)):
        mini = i
        for j in range(i, len(A)):
            if A[j] < A[mini]:
                mini = j
        if i != mini:
            A[i], A[mini] = A[mini], A[i]
            cnt += 1
    return A, cnt

N = int(input())
A = [int(_) for _ in input().split()]

A, cnt = SelectionSort(A)
print(" ".join([str(i) for i in A]))
print(cnt)

