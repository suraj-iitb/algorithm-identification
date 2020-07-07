N = int(input())
A = list(map(int, input().split()))

def bubblesort(A, N):
    flag = True
    i = 0
    cnt = 0
    while flag:
        flag = False
        for j in range(N-1, i, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                flag = True
                cnt += 1
        i += 1     
    print(*A)
    print(cnt)

bubblesort(A,N)
