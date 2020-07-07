def insertionSort(A, N):
    for i in range(N):
        s = ""
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
            A[j+1] = v
        print(' '.join(map(str, A)))
            
if __name__ == '__main__':
    N = int(input()) #1行目のNを取得する
    M = list(map(int,input().split()))
    insertionSort(M, N)
