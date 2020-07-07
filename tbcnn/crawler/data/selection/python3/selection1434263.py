def selection_sort(A):
    count = 0
    for i in range(len(A)):
        min_j = i
        for j in range(i, len(A)):
            if A[j] < A[min_j]:
                min_j = j
        if i != min_j:
            A[i], A[min_j] = A[min_j], A[i]
            count += 1
    return A, count

if __name__ == '__main__':
    n = int(input())
    array, count = selection_sort(list(map(int, input().split())))
    print(' '.join(map(str, array)))
    print(count)
