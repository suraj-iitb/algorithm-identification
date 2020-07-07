# coding: utf-8

def bubbleSort(A, N):
    flag = 1
    c = 0
    while flag:
        flag = 0
        for j in range(N - 1, 0, -1):
            if A[j] < A[j - 1]:
                A[j], A[j - 1] = A[j - 1], A[j]
                c += 1
                flag = 1
    print(' '.join(map(str, A)))
    print(c)


if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    bubbleSort(A, N)
