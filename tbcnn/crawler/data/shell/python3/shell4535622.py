def insertion_sort(A,n,g):
    cnt = 0
    for i in range(g,n):
        v = A[i]
        j = i - g
        while (j>=0)&(A[j]>v):
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v
    return A, cnt
    
    
def shell_sort(A,n):
    G = []
    g = 1
    while True:
        G.append(g)
        g = 3*g+1
        if g>n:
            break
    m = len(G)
    G = G[::-1]
    cnt = 0
    for i in range(m):
        A,cnt_tmp = insertion_sort(A,n,G[i])
        cnt += cnt_tmp
    return G,A,cnt
    

n = int(input())
A = [int(input()) for i in range(n)]

G,A,cnt = shell_sort(A,n)
print(len(G))
print(*G)
print(cnt)
for i in range(n):
    print(A[i])
