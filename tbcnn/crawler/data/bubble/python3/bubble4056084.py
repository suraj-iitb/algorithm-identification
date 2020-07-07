def BubbleSort(A, N):
    cnt = 0  # 隣接要素の交換回数
    t = 0
    for i in range(N):   # iは未ソートの部分列の先頭のインデックス
        t = cnt
        for j in range(N-1, i, -1):     # 隣接要素を比較するのは未ソート部分列の末尾から先頭まで
            if A[j-1] > A[j]:           # 隣接要素を比較
                A[j-1], A[j] = A[j], A[j-1]     # 大小関係が逆の場合、交換
                cnt += 1        # 交換回数をカウント
        if t == cnt:
            return A, cnt

N = int(input())
A = list(map(int, input().split()))

ans, cnt = BubbleSort(A,N)
print(*ans)    # リストの中身を値で取り出す
print(cnt)
