import sys
input = sys.stdin.readline


def main():
    N = int(input())
    P = list(map(int, input().split()))
    print(' '.join(map(str, P)))
    insertionSort(N, P)


def insertionSort(N, P):
    for i in range(1, N):
        v = P[i]
        j = i - 1
        while j >= 0 and P[j] > v:
            P[j + 1] = P[j]
            j -= 1
        P[j + 1] = v

        print(' '.join(map(str, P)))


if __name__ == '__main__':
    main()

