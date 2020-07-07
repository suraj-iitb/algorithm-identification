cnt = int(input())
numbers = list(map(int, input().split(' ')))


def bubblesort(A, N):
    swap_cnt = 0
    flag = True
    while flag:
        flag = False
        for j in range(N-1, 0, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                swap_cnt += 1
                # ループで一回でもswapしたらTrueとなる
                flag = True

    return A, swap_cnt


numbers, swap_cnt = bubblesort(numbers, cnt)
print(' '.join(map(str, numbers)))
print(swap_cnt)
