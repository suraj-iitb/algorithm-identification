def bubbleSort(A, N):
    ret = 0
    flag = 1
    while flag:
        flag = 0
        for j in range(N-1, 0, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                flag = 1
                ret += 1
    return ret


n = int(input())
a = list(map(int, input().split()))
count = bubbleSort(a, n)
print(" ".join(map(str, a)))
print(count)
