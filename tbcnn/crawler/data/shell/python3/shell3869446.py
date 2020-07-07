# ALDS1_2_D
n = int(input())
A = [int(input()) for _ in range(n)]


def insertionSort(A, n, g):
    global cnt
    for i in range(g, n, 1):
        v = A[i]
        j = i - g
        while (j >= 0) & (A[j] > v):
            A[j + g] = A[j]
            j -= g
            cnt += 1
        A[j + g] = v


def trace(A):
    for i in range(len(A)):
        if i != len(A) - 1:
            print(A[i], end='\n')
        else:
            print(A[i], end='')


G = []
h = 1
G.append(h)
while h < n:
    G.append(h)
    h = 5 * h + 1
m = len(G)
G.reverse()

cnt = 0
for i in G:
    insertionSort(A, n, i)

print(m)
for i in range(len(G)):
    print(G[i], end=' ')
    if i == len(G) - 1:
        print('')
print(cnt)
trace(A)

