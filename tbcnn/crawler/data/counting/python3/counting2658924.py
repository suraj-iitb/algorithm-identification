def main():
    _ = input()
    li = [int(x) for x in input().split(' ')]
    out = countingSort(li, max(li))
    print(*out)


def countingSort(A, k):
    B = []
    for _ in range(len(A)):
        B.append(0)

    C = []
    for _ in range(k + 1):
        C.append(0)

    for a in A:
        C[a] += 1

    for i in range(1, k + 1):
        C[i] = C[i] + C[i - 1]

    for j in range(len(A) - 1, -1, -1):
        B[C[A[j]] - 1] = A[j]
        C[A[j]] -= 1

    return B


main()
