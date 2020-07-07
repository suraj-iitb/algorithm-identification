if __name__ == "__main__":
    n = int(input())
    A = list(map(int, input().split()))

    swap_count = 0
    flag = True
    while flag:
        flag = 0
        for j in range(1, n):
            if A[j-1] > A[j]:
                A[j], A[j-1] = A[j-1], A[j]
                flag = 1
                swap_count += 1

    print(' '.join(map(str, A)))
    print(swap_count)

