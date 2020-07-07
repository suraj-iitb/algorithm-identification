# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_A

from sys import stdin
input = lambda: stdin.readline().rstrip()

N = int(input())

A = list(map(int, input().split()))

join = lambda a : ' '.join(map(str, a))
print(join(A))
for i in range(1,N):
    v = A[i]
    j = i - 1
    while j >= 0 and A[j] > v:
        A[j+1] = A[j]
        j = j-1
    A[j+1] = v
    print(join(A))

