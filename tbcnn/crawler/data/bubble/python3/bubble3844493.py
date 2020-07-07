# ALDS1_2_A - Bubble Sort
def main():
    N, *A = map(int, open(0).read().split())
    ans = 0
    for i in range(N):
        for j in range(N - 1, i, -1):
            if A[j] < A[j - 1]:
                A[j], A[j - 1] = A[j - 1], A[j]
                ans += 1
    print(*A)
    print(ans)


if __name__ == "__main__":
    main()
