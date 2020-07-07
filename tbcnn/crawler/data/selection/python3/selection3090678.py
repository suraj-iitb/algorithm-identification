cnt = int(input())
numbers = list(map(int, input().split(' ')))


def selectionsort(A, N):
    '''
    :param A: N個の要素を含む０オリジンの配列
    :param N: Aの要素数
    :return:
    '''
    swap_cnt = 0

    for i in range(0, N):
        minj = i
        for j in range(i+1, N):
            if A[j] < A[minj]:
                minj = j

        if minj != i:
            A[i], A[minj] = A[minj], A[i]
            swap_cnt += 1

    return ' '.join(map(str, A)), swap_cnt

numbers, swap_cnt = selectionsort(numbers, cnt)
print(numbers)
print(swap_cnt)

