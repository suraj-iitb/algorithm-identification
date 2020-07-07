def InsertionSort(A, N):
    for i in range(N):
        v = A[i]       # A[i]は未ソート部分の先頭
        j = i - 1
        while j >= 0 and A[j] > v: 
            A[j+1] = A[j]  # vよりも大きい要素を一つ右に移動させる
            j -= 1     # 比較する位置を移動
        A[j+1] = v     # 空いた部分にvを入れる
        print(*A)

N = int(input())
A = list(map(int, input().split()))

InsertionSort(A, N)
