from collections import Counter
from itertools import accumulate


def counting_sort(A, k):
    counter = Counter(A)
    B = [0]*(len(A)+1)
    C = list(accumulate((counter[i] for i in range(k+1))))
    for n in A[::-1]:
        B[C[n]] = n
        C[n] -= 1

    return B[1:]


if __name__ == "__main__":
    input()
    a = list(map(int, input().split()))
    print(*counting_sort(a, 10000))
