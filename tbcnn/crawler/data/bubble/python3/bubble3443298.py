N = int(input())
A = list(map(int, input().split()))

def bubbleSort(A, N):
    flag = 1
    count = 0
    while flag:
        flag = 0
        for j in range(N-1, 0, -1):
            if A[j]<A[j-1]:
                tmp = A[j]
                A[j] = A[j-1]
                A[j-1] = tmp
                count += 1
                flag = 1
    return A, count

A, count = bubbleSort(A, N)
print(*A)
print(count)