def showList(A, N):
    for i in range(N-1):
        print(A[i],end=' ')
    print(A[N-1])

def selectionSort(A, N):
    """
    選択ソート
    O(n^2)のアルゴリズム
    """
    count = 0
    for i in range(N):
        minj = i
        for j in range(i,N):
            if A[j] < A[minj]:
                minj = j
        if minj != i:
            t = A[minj]
            A[minj] = A[i]
            A[i] = t
            count += 1
    showList(A, N)
    print(count)
    

N = int(input())
A = [int(x) for x in input().split(' ')]
selectionSort(A, N)
