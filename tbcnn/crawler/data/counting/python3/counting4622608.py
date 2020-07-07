import sys


def main():
    N = int(sys.stdin.readline())
    A = [int(x) for x in sys.stdin.readline().split()]

    C = [0] * (max(A) + 1)

    # 個数を数える
    for a in A:
        C[a] += 1

    for i in range(1, len(C)):
        C[i] = C[i] + C[i - 1]

    B = [None] * N

    # 個数に基づいて新しい配列を設定する

    for a in reversed(A):
        # print(a, C[a], C)
        B[C[a] - 1] = a
        C[a] -= 1

    print(" ".join(list(str(x) for x in B)))


main()

