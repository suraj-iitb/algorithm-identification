def BubbleSort(A):
    count = 0
    for i in range(len(A)):
        for j in reversed(range(len(A) - 1, 0, -1)):
            if A[j] < A[j - 1]:
                A[j], A[j - 1] = A[j - 1], A[j]
                count += 1
    return A, count

N = int(input())
A = list(map(int, input().split()))
bubble_sort, count = BubbleSort(A)
print(*bubble_sort)
print(count)
