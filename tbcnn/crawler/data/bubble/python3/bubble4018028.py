
def ALDS1_2_A():
    """
    1 bubbleSort(A, N) // N 個の要素を含む 0-オリジンの配列 A
    2   flag = 1 // 逆の隣接要素が存在する
    3   while flag
    4     flag = 0
    5     for j が N-1 から 1 まで
    6       if A[j] < A[j-1]
    7         A[j] と A[j-1] を交換
    8         flag = 1

    ＜問題＞
    数列 A を読み込み、バブルソートで昇順に並び変え出力するプログラムを作成してください。
    また、バブルソートで行われた要素の交換回数も報告してください。

    ＜入力＞
    入力の最初の行に、数列の長さを表す整数 N が与えられます。２行目に、N 個の整数が空白区切りで与えられます。

    ＜出力＞
    出力は 2 行からなります。１行目に整列された数列を 1 行に出力してください。数列の連続する要素は１つの空白で区切って出力してください。
    2 行目に交換回数を出力してください。

    ＜制約＞
    1 ≤ N ≤ 100
    0 ≤ A の要素 ≤ 100
    """
    N = int(input())
    A = [int(e) for e in input().split(" ")]
    flag = 1    # A[j] < A[j-1] の要素が存在するかのflag変数
    switch_cnt = 0
    idx_not_sorted = 0
    while flag:
        flag = 0
        for j in range(N-1, idx_not_sorted, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                switch_cnt += 1
                flag = 1
        idx_not_sorted += 1
    print(" ".join(map(str, A)))
    print(switch_cnt)


def main():
    ALDS1_2_A()


if __name__ == '__main__':
    main()
