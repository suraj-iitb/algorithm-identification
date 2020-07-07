def bubbleSort(A, N):
    swap_count = 0
    flag = True
    while flag:
        flag = False
        for j in range(N-1, 0, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                flag = True
                swap_count += 1
    return swap_count

n = int(input())
A = list(map(int, input().split()))
count = bubbleSort(A,n)
print(*A)
print(count)
