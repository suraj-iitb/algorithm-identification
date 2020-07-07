def select_sort(A, N):
    cnt = 0
    for i in range(N):
        mini_ix = i
        for j in range(i, N):
            if A[mini_ix] > A[j]:
                mini_ix = j

        if mini_ix != i:  # ここでswap
            A[i], A[mini_ix] = A[mini_ix], A[i]
            cnt += 1

    print(*A, sep=' ')
    print(cnt)


def main():
    N = int(input())
    A = list(map(int, input().split()))
    select_sort(A, N)


if __name__ == "__main__":
    main()
