# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_A

from sys import stdin
input = lambda: stdin.readline().rstrip()

N = int(input())
A = list(map(int, input().split()))

f = True
i = 0
cnt = 0
while f:
    f = False
    for j in reversed(range(1+i, N)):
        if A[j] < A[j-1]:
            w = A[j]
            A[j] = A[j-1]
            A[j-1] = w
            f = True
            cnt = cnt+1
    i = i+1

print(' '.join(map(str, A)))
print(cnt)
