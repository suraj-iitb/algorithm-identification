N = int(input())
A = list(map(int, input().split()))

def selectionSort(A, N):
    cnt = 0
    
    for i in range(N):
        A_ = A[i:]
        j = A_.index(min(A_)) + i
        if A[j] < A[i]:
            temp = A[i]
            A[i] = A[j]
            A[j] = temp
            cnt += 1
                
    print(*A)
    print(cnt)
    
selectionSort(A, N)
