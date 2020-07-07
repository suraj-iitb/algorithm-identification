def insertion_sort(A, n, g):
    cnt = 0
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v

    return cnt

n = int(input())

A = [int(input()) for _ in range(n)]

G = [1]
G[0] = 1
for i in range(1, 100):
    G.append(G[i-1] * 3 + 1)
    if G[i] > n:
        del G[-1]
        break

m = len(G)
cnt = 0
for i in range(m):
    cnt += insertion_sort(A, len(A), G[m-1-i])

print(m)
print(*reversed(G))
print(cnt)
print(*A, sep='\n')
