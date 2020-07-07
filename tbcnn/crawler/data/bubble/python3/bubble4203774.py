def bubbleSort(A, N):
    cnt = 0
    flag = 1
    while flag:
        flag = 0
        for j in range(N - 1, 0, -1):
            if A[j] < A[j - 1]:
                A[j], A[j - 1] = A[j - 1], A[j]
                flag = 1
                cnt = cnt + 1
    return cnt


N = int(input())
A = [int(i) for i in input().split()]
cnt = bubbleSort(A, N)
for i in range(len(A)):
    if i:
        print(" ", end = "")
    print(A[i], end = "")
print()
print(cnt)
