def insert(A,n,g):
    global cnt
    for i in range(g,n):
        v = a[i]
        j = i-g
        while(j>=0 and A[j]>v):
            A[j+g] = A[j]
            j = j-g
            cnt+= 1
        A[j+g] = v
        
def shell(A,n):
    global cnt
    cnt = 0
    G = []
    h = 1
    while h <= n:
        G.append(h)
        h = 3*h+1
    G.reverse()
    m = len(G)
    print(m)
    print(" ".join(map(str,G)))
    for i in G:
        insert(A,n,i)
    return cnt
        
n = int(input())
a = []
for i in range(n):
    ai = int(input())
    a.append(ai)
    
shell(a,n)
print(cnt)

for i in range(n):
    print(a[i])
