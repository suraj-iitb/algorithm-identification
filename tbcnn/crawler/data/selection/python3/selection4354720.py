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


ans = 0

for i in range(N):
    m = i
    for j in range(i + 1, N):
        if A[j] < A[m]:
            m = j
    if m != i:
        ans += 1
        A[m], A[i] = A[i], A[m]

p(A)
print(ans)

