def main():
    N = int(input())
    A = list(map(int, input().split()))

    ans = 0

    for i in range(N - 1):
        for j in range(N-1, i, -1):
            if A[j - 1] > A[j]:
                A[j - 1], A[j] = A[j], A[j - 1]
                ans += 1

    print(" ".join(list(map(str, A))))
    print(ans)

main()
