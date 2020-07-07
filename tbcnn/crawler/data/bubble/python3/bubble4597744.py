import sys

input = sys.stdin.readline


def main():
    N = int(input())
    A = list(map(int, input().split()))

    ans = 0
    at_least_once = True
    while at_least_once:
        at_least_once = False
        for i in range(N - 1):
            if A[i] > A[i + 1]:
                A[i], A[i + 1] = A[i + 1], A[i]
                at_least_once = True
                ans += 1

    print(" ".join(map(str, A)))
    print(ans)


if __name__ == "__main__":
    main()

