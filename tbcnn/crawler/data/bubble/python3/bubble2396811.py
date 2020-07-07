N = int(input())
A = [int(i) for i in input().split()]

def BubbleSort(N, A):
    flag = 1
    cnt = 0
    while flag > 0:
        flag = 0
        for j in range(N-1, 0, -1):
            if A[j] < A[j-1]:
                tmp = A[j]
                A[j] = A[j-1]
                A[j-1] = tmp
                flag = 1
                cnt += 1
    return A, cnt

res = BubbleSort(N, A)
print(" ".join(map(str, res[0])))
print(res[1])
