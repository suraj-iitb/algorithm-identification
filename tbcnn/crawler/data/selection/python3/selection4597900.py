import sys

input = sys.stdin.readline


def main():
    N = int(input())
    A = list(map(int, input().split()))

    ans = 0
    for i in range(N - 1):
        min_j = i
        for j in range(i, N):
            if A[j] < A[min_j]:
                min_j = j
        if min_j != i:
            A[i], A[min_j] = A[min_j], A[i]
            ans += 1

    print(" ".join(map(str, A)))
    print(ans)


if __name__ == "__main__":
    main()

