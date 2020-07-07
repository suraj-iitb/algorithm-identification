
def ALDS1_2_B():
    """
    1 selectionSort(A, N) // N個の要素を含む0-オリジンの配列A
    2   for i が 0 から N-1 まで
    3     minj = i
    4     for j が i から N-1 まで
    5       if A[j] < A[minj]
    6         minj = j
    7     A[i] と A[minj] を交換

    ＜問題＞
    数列Aを読み込み、選択ソートのアルゴリズムで昇順に並び替え出力するプログラムを作成してください。
    上の疑似コードに従いアルゴリズムを実装してください。
    疑似コード 7 行目で、i と minj が異なり実際に交換が行われた回数も出力してください。

    ＜入力＞
    入力の最初の行に、数列の長さを表す整数 N が与えられます。２行目に、N 個の整数が空白区切りで与えられます。

    ＜出力＞
    出力は 2 行からなります。１行目に整列された数列を 1 行に出力してください。
    数列の連続する要素は１つの空白で区切って出力してください。2 行目に交換回数を出力してください。

    ＜制約＞
    1 ≤ N ≤ 100
    0 ≤ A の要素 ≤ 100
    """
    N = int(input())
    A = [int(e) for e in input().split(" ")]
    switch_cnt = 0
    for i in range(N):
        min_j = i
        for j in range(i, N):
            if A[j] < A[min_j]:
                min_j = j
        if i != min_j:
            A[i], A[min_j] = A[min_j], A[i]
            switch_cnt += 1
    print(" ".join(map(str, A)))
    print(switch_cnt)


def main():
    ALDS1_2_B()


if __name__ == '__main__':
    main()
