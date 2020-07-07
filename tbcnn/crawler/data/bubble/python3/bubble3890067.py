import sys
input = sys.stdin.readline


def main():
    N = int(input())
    P = list(map(int, input().split()))
    bubbleSort(N, P)


def bubbleSort(N, P):
    change_count = 0
    i = 0
    while True:
        for j in range(N - 1, i, -1):
            if P[j] < P[j - 1]:
                tmp = P[j]
                P[j] = P[j - 1]
                P[j - 1] = tmp
                change_count += 1
        i += 1
        # print("i:{}".format(i))
        if i == N:
            break

    print(' '.join(map(str, P)))
    print(change_count)


if __name__ == '__main__':
    main()

