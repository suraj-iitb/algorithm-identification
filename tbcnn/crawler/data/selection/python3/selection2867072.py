def selection_sort(A):
    count = 0
    for i in range(len(A)):
        minj = i
        for j in range(i, len(A)):
            if A[j] < A[minj]:
                minj = j
        if minj != i:
            A[i], A[minj] = A[minj], A[i]
            count += 1
    return A, count

if __name__ == '__main__':
    n = int(input())
    A = [int(x) for x in input().split()]
    result_A, count = selection_sort(A)
    print(*result_A)
    print(count)

