# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_B

from sys import stdin
input = lambda: stdin.readline().rstrip()

N = int(input())
A = list(map(int, input().split()))

cnt = 0
for i in range(0, N-1):
    minj = i
    for j in range(i+1, N):
        if A[j] < A[minj]:
            minj = j

    if i != minj:
        w = A[i]
        A[i] = A[minj]
        A[minj] = w
        cnt = cnt + 1

print(' '.join(map(str,A)))
print(cnt)
