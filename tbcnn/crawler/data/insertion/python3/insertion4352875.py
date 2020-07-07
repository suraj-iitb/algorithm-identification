from sys import stdin
input = stdin.readline

N = int(input())
A = list(map(int, input().split()))


def p(N):
    for i in range(len(N)):
        if i == len(N) - 1:
            print(N[i])
        else:
            print(N[i], end=" ")


p(A)

for i in range(1, N):
    s = A[i]
    j = i - 1

    while j >= 0 and A[j] > s:
        A[j + 1] = A[j]
        j -= 1

    A[j + 1] = s

    p(A)

