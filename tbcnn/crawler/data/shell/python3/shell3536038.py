#シェルソート
def insertionSort(A, n, g):
    global cnt
    for i in range(g, n):
        #その間隔で比較できる最も左から始める.vが基準値
        v = A[i]
        j = i - g 
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j -= g
            cnt += 1
        A[j+g] = v

n = int(input())
A = [int(input()) for i in range(n)]

cnt = 0
G = [1]
for i in range(100):
    if n < 1 + 3*G[-1]:
        break
    G.append(1+3*G[-1])
m = len(G)
G.reverse()

for i in range(m):
    insertionSort(A, n, G[i])

print(m)
print(*G)
print(cnt)
print(*A, sep='\n')
