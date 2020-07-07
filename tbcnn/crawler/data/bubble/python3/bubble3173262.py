n = int(input())
a = list(map(int, input().split()))

def bubbleSort(A, N):
    cnt = 0
    flag = True
    while flag:
        flag = False
        for j in range(N-1, 0, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                cnt += 1
                flag = True
    return A, cnt
    
result = bubbleSort(a, n)
print(' '.join(map(str, result[0])))
print(result[1])

