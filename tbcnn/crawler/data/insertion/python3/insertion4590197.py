import sys

input = sys.stdin.readline


def main():
    N = int(input())
    A = list(map(int, input().split()))

    for i in range(N):
        v = A[i]
        j = i - 1
        while 0 <= j and A[j] > v:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = v
        print(" ".join(map(str, A)))


if __name__ == "__main__":
    main()

