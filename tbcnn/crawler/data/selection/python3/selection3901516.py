def SelectionSort(A):
    count = 0
    for i in range(len(A)):
        mini = i
        for j in range(i, len(A)):
            if A[j] < A[mini]:
                mini = j
        if A[i] != A[mini]:
            A[i], A[mini] = A[mini], A[i]
            count += 1
    return A, count

N = int(input())
A = list(map(int, input().split()))
selection_sort, count = SelectionSort(A)
print(*selection_sort)
print(count)
