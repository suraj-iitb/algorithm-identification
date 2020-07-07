def BubbleSort(A, N):
    if N == 1:
        print(str(A[0]) + "\n" + str(0))
    else:
        count = 0
        for i in range(N): #このiは使わない
            for j in range(N - i - 1):
                if A[N - j - 1] < A[N - j - 2]: #わかりにくくなってしまった
                    count += 1
                    A[N - j - 1], A[N - j - 2] = A[N - j - 2], A[N - j - 1] 
        str_A = map(str, A)
        print(" ".join(str_A) +  "\n" + str(count))

n = int(input())
a = list(map(int, input().split()))

BubbleSort(a, n)
