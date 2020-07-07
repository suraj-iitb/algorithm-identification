n = int(input())
A = list(map(int, input().split()))

def bubbleSort(A, N):
    flag = 1
    cnt = 0
    
    while flag:
        flag = 0
        for i in range(N-1, 0, -1):
            if A[i] < A[i-1]:
                temp = A[i]
                A[i] = A[i-1]
                A[i-1] = temp
                flag = 1
                cnt += flag
            
    print(*A)
    print(cnt)
    
bubbleSort(A, n)
