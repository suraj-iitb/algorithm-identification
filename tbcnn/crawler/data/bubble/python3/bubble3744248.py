def bubbleSort(A, N):
    count = 0
    flag = 1
    while flag:
        flag = 0
        j = N-1
        while j != 0:
            if A[j] < A[j-1]:
                out = A[j-1]
                A[j-1] = A[j]
                A[j] = out
                flag = 1
                count += 1
            j -= 1
    print(' '.join(map(str, A)))
    print(str(count))
            
if __name__ == '__main__':
    N = int(input()) #1行目のNを取得する
    M = list(map(int,input().split()))
    bubbleSort(M, N)
