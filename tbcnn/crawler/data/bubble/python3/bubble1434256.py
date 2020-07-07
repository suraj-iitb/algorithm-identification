def bubble_sort(A):
    count = 0
    flag = True
    while flag:
        flag = False
        for j in reversed(range(1, len(A))):
            if A[j] < A[j - 1]:
                A[j], A[j - 1] = A[j - 1], A[j]
                flag = True
                count += 1
    return A, count

if __name__ == '__main__':
    n = int(input())
    array, count = bubble_sort(list(map(int, input().split())))
    print(' '.join(map(str, array)))
    print(count)
