def insertionSort(A, n, g):
    global cnt
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v


def shellSort(A, n):
    global cnt
    global m
    global G
    for i in range(m):
        insertionSort(A, n, G[i])


n = int(input())
A = [int(input()) for i in range(n)]

cnt = 0
G = [1]
while G[-1] < n/9:
    G.append(G[-1]*3 + 1)
G.reverse()
m = len(G)

shellSort(A, n)
print(m)
print(" ".join(map(str, G)))
print(cnt)
for i in A:
    print(i)
