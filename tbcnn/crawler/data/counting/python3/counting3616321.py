def counting_sort(A, B, k):
    n = len(A)
    B = [0] * n

    C = [0] * (k+1)

    # カウント
    for a in A:
        # print(a)
        C[a] += 1
    # print(*C)
    # print('just done')

    # 累積カウント
    for i in range(1, k+1):
        C[i] += C[i-1]

    # print(*C)

    # Bに移植
    for i in range(n-1, -1, -1):
        index_to_insert = C[A[i]] - 1
        C[A[i]] -= 1
        B[index_to_insert] = A[i]
        # print(*C)

    return B

_ = int(input())
A = list(map(int, input().split()))

B = []
B = counting_sort(A, B, 10000)
print(*B)
