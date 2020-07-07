import math

def insert_sort(A, n, g):
    cnt = 0
    for i in range(g, n):
        j = i - g
        v = A[i]
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j -= g
            cnt += 1
        A[j+g] = v
    return cnt

def shell_sort(A, n):
    cnt = 0
    
    G = []
    h = 1
    while h <= n:
        G.append(h)
        h = h*3+1
    
    G.reverse()
    
    print(len(G))
    print(*G)
        
    for g in G:
        cnt += insert_sort(A, n, g)
    return cnt

N = int(input())
A = [int(input()) for _ in range(N)]

cnt = shell_sort(A, N)

print(cnt)

for a in A:
    print(a)

