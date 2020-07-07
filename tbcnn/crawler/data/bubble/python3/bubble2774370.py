def bubbleSort(A, N): # N 個の要素を含む 0-オリジンの配列 A
    A = list(map(int, A.split()))
    flag = 1 # 逆の隣接要素が存在する
    count = 0  # 交換回数
    while flag:
        flag = 0
        for j in range(N-1, 0, -1):
            if A[j] < A[j-1]:
                # A[j] と A[j-1] を交換
                tmp = A[j]
                A[j] = A[j-1]
                A[j-1] = tmp
                flag = 1
                count += 1
    print(" ".join(map(str,A)))
    print(count)

N = int(input())
A = input()
bubbleSort(A, N)
