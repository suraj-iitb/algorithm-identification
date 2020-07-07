import sys
input = sys.stdin.readline


def main():
    N = int(input())
    P = list(map(int, input().split()))
    selectionSort(N, P)


def selectionSort(N, P):
    change_count = 0
    for i in range(0, N):
        minj = i

        # print(P[i:N])
        # print(min(P[i:N]))

        for j in range(i, N):
            if P[j] < P[minj]:
                minj = j

        if i != minj:
            tmp = P[i]
            P[i] = P[minj]
            P[minj] = tmp
            change_count += 1

        # print(' '.join(map(str, P)))

    print(' '.join(map(str, P)))
    print(change_count)


if __name__ == '__main__':
    main()

