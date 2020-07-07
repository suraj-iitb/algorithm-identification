g_m=0
g_G=[]
g_cnt=0
A=[]
n = int(input())
for i in range(n):
    A.append(int(input()))
def insertionSort(A,n,g):
    global g_cnt
    for i in range(g,n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j-g
            g_cnt += 1
        A[j+g]=v
    
def shellSort(A,n):
    m=1
    G=[]
    j=1
    for i in range(0,100):
        G.append(j)
        j=3*j+1
    
    while G[m]<=n:
        m+=1
    G=G[:m]
    G.reverse()
    for i in range(0,m):
        insertionSort(A,n,G[i])
    return A,m,G
A,g_m,g_G=shellSort(A,n)
print(g_m)
print(" ".join(map(str,g_G)))
print(g_cnt)
print(*A,sep="\n")
