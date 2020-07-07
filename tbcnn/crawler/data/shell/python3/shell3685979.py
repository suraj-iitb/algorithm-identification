n = int(input())
A = [int(input()) for i in range(n)]
def InsertionSort(A, n, g):
    global c
    for i in range(g, n):
        v = A[i]
        j = i - g
        while A[j] > v and j >= 0:
            A[j+g] = A[j]
            j -= g
            c += 1
        A[j+g] = v
    
G = [1]
while G[-1]*3 + 1 <= n:
    G.append(G[-1]*3 + 1)

G.reverse()
m = len(G)
print(m)
print(*G)
c = 0
for g in G:
    InsertionSort(A, n, g)
    
print(c)
print(*A, sep="\n")            
    
