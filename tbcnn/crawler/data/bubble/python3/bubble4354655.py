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


flag = True
ans = 0

while flag:
    flag = False
    for i in range(N - 1, 0, -1):
        if A[i] < A[i - 1]:
            A[i], A[i - 1] = A[i - 1], A[i]
            ans += 1
            flag = True

p(A)
print(ans)

