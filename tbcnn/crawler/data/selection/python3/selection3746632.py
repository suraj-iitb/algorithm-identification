"""
1 selectionSort(A, N) // N個の要素を含む0-オリジンの配列A
2   for i が 0 から N-1 まで
3     minj = i
4     for j が i から N-1 まで
5       if A[j] < A[minj]
6         minj = j
7     A[i] と A[minj] を交換
"""
def selectionSort(A, N):
    count = 0
    B = []
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        out = A[i]
        A[i] = A[minj]
        A[minj] = out
        if(A[i]!=A[minj]):
            count += 1
            
    print(' '.join(map(str, A)))
    print(str(count))
    
if __name__ == '__main__':
    N = int(input()) #1行目のNを取得する
    M = list(map(int,input().split()))
    selectionSort(M, N)
