def insertionSort(A, n, g):
    cnt_local = 0
    for i in range(g, n):
        v = A[i]
        j = i - g
        while (j >= 0 and A[j] > v):
            A[j+g] = A[j]
            j = j - g
            cnt_local += 1
        A[j+g] = v
    return cnt_local

cnt_all = 0
n = int(input())
A = []
for _ in range(n):
    A.append(int(input()))

G = [int((3**i-1)/2)for i in range(17,0,-1)]
G = [v for v in G if v <= n]
m = len(G)
for i in range(m):
    cnt_all += insertionSort(A, n, G[i])

print(m)
print(*G)
print(cnt_all)
print(*A, sep='\n')

