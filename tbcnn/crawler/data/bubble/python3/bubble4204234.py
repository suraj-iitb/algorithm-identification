n = int(input())
a = list(map(int, input().split()))

def bubbleSort(A, N):
    flag = 1 #逆の隣接要素が存在する
    cnt = 0
    while flag:
        flag = 0
        for j in range(n-1, 0, -1):#が N-1 から 1 まで:
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                cnt += 1
                flag = 1
    print(*A)
    print(cnt)
    
bubbleSort(a, n)
