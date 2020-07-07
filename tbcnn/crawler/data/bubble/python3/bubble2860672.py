def bubble_sort(A):
    flag = True
    count = 0
    while flag:
        flag = False
        for j in range(len(A)-1, 0, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                flag = True
                count += 1
    return A, count

if __name__ == '__main__':
    n = int(input())
    A = [int(x) for x in input().split()]
    result_A, count = bubble_sort(A)
    print(*result_A)
    print(count)
