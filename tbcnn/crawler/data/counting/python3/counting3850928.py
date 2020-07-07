n = int(input())
A = list(map(int, input().split()))
B = [0 for i in range(n)]

def countingsort(A, B, k):
    """リストAの0からk以下の各要素の数（計n）をカウントするリストCを作成（初期値0）"""
    C = [0 for i in range(k)]
    """リストAの各要素の数をリストCに記録（Cのインデックス=Aの値）"""
    for i in range(n):
        C[A[i]] += 1
    """C[i]にi以下の値の出現数を記録"""
    for i in range(1, k):
        C[i] += C[i-1]
    """リストBに値をソートしつつ格納"""
    for i in reversed(range(n)):
        B[C[A[i]] - 1] = A[i]
        C[A[i]] -= 1

countingsort(A, B, max(A)+1)
print(*B)
