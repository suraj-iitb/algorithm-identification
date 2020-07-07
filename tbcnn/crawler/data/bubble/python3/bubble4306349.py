def bubbleSort(A, N):
    cnt = 0
    flag = 1
    
    while flag:
        flag = 0
        for j in reversed(range(1, N)):
            if A[j] < A[j-1]:
                A = A[:j-1] + A[j-1:j+1][::-1] + A[j+1:]
                cnt += 1
                flag = 1
                
    print(*A)
    print(cnt)
                
n = int(input())
a = list(map(int, input().split()))
bubbleSort(a, n)
