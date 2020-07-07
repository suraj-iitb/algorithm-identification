import sys
input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))
B = [0 for _ in range(len(A))]
k = 10000


def main():
    CountingSort(A, B, k)
    print(' '.join(map(str, B)))


def CountingSort(A, B, k):
    C = [0 for _ in range(k)]

    # Aの要素iの出現回数をCiに書きこむ
    for i in range(n):
        C[A[i]] += 1

    # 累積和を求める
    for i in range(k):
        if i > 0:
            C[i] = C[i] + C[i - 1]

    for j in range(len(B) - 1, -1, -1):
        B[C[A[j]] - 1] = A[j]
        C[A[j]] -= 1


if __name__ == '__main__':
    main()

