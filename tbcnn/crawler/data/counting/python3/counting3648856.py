A_NUM_MAX = 10001


def counting_sort(A):
    B = [None] * len(A)
    C = [0] * A_NUM_MAX

    for a in A:
        C[a] += 1

    for i in range(1, A_NUM_MAX):
        C[i] += C[i - 1]

    for a in reversed(A):
        B[C[a] - 1] = a
        C[a] -= 1

    return B


n = int(input())
A = list(map(int, input().split()))

B = counting_sort(A)

print(*B)
