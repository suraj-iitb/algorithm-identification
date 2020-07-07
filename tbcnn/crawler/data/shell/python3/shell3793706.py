import math

def insertion_sort(A, n, g):
    c = 0
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j + g] = A[j]
            j -= g
            c += 1
        A[j + g] = v
    return c

cnt = 0
n = int(input())

A = []
G = []

m = 0
ge = 1

while ge <= n:
    G.append(ge)
    m += 1
    ge = 3 * ge + 1
G.reverse()

for _ in range(n):
    A.append(int(input()))

for i in range(m):
    cnt += insertion_sort(A, n, G[i])

print(str(m))
print(' '.join([ str(g) for g in G ]))
print(str(cnt))

for j in range(n):
    print(str(A[j]))
