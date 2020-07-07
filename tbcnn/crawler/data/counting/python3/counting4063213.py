def counting_sort(A, k):
    """整数列 A を昇順に計数ソートでソートした新しいリストを返す。

    A 内の整数 x はすべて 0 <= x <= k の範囲にある。
    """
    # A 内の整数 i の出現数を C[i] に記録していく。
    C = [0 for _ in range(0, k + 1)]
    for x in A:
        C[x] += 1
    
    # A 内の整数のうち、i 以下の出現頻度を C[i] に記録する。
    for i in range(1, k + 1):
        C[i] += C[i - 1]
    
    n = len(A)
    B = [ None for _ in range(n) ]
    for j in range(n - 1, -1, -1):
        B[C[A[j]] - 1] = A[j]   # 逆順にすることで安定なソートになる。
        C[A[j]] -= 1
    
    return B

if __name__ == '__main__':
    import sys

    n = int(input())
    A = list(map(int, sys.stdin.readline().split()))
    k = max(A)

    print(*counting_sort(A, k))

