def bubbleSort(A, N):
    flag = 1
    count = 0
    while flag:
        flag = 0
        for j in range(N - 1, 0, -1):
            if A[j] < A[j - 1]:
                A[j], A[j - 1] = A[j - 1], A[j]
                flag = 1
                count += 1
    return count


n = int(input())
a = [int(i) for i in input().split()]
count = bubbleSort(a, n)
print(" ".join(map(str, a)))
print(count)

