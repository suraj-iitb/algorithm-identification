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

n = int(input())
A = [int(input()) for _ in range(n)]

cnt = 0
G = [1]
for i in range(100):
    if n < 3*G[i] + 1:
        break
    G.append(3*G[i] + 1)
G.reverse()
m = len(G)

for i in range(m):
    insertionSort(A, n, G[i])
    
print(m)
print(" ".join(map(str, G)))
print(cnt)
print("\n".join(map(str, A)))
