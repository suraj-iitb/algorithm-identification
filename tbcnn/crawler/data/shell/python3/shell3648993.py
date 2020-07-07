n = int(input())
A = []
for i in range(n):
    A.append(int(input()))

cnt = 0

G = [1]

for i in range(n):
    i += 1
    val = 3 * G[i-1] + 1
    if val > n // 2:
        break
    G.append(val)

G.reverse()

def insertionSort(A, n, g):
    global cnt
    for i in range(g, n, 1):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v

def shellSort(A, n):
    print(len(G))
    print(" ".join(list(map(str, G))))
    for i in range(len(G)):
        insertionSort(A, n, G[i])


shellSort(A, n)

print(cnt)
for v in A:
    print(v)

