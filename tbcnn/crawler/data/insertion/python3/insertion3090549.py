# 挿入ソート　トランプの時によく使う。
#
#
#
#

cnt = int(input())
numbers = list(map(int, input().split(' ')))


def insertionsort(A, N):
    '''
    :param A: N個の要素を含む０オリジンの配列
    :param N: Aの要素数
    :return:
    '''
    print(' '.join(map(str, A)))

    for i in range(1, N):
        # ずらすために一時保存しておく変数
        v = A[i]
        # ソート済み部分のindex
        j = i - 1
        # 探索 jが-1になったとき か 自分よりソート済みが小さい場合
        while j >= 0 and A[j] > v:
            # ソート済み部分を右に１個ずらす
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v

        print(' '.join(map(str, A)))

insertionsort(numbers, cnt)

