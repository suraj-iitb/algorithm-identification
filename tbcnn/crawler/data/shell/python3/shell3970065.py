#shell sort
def insert(A,n,g):
    c=0
    for i in range(g,n):
        v = A[i]
        j = i-g
        while j>=0 and A[j]>v:
            A[j+g]=A[j]
            j=j-g
            c+=1
        A[j+g]=v
    return [A,c]

def shell(A,n):
    cn=0
    G=[1]
    while 3*G[0]+1 < n:
        G.insert(0,G[0]*3+1)
    m=len(G)
    for i in G:
        cn+=insert(A,n,i)[1]
        A=insert(A,n,i)[0]
    return [m,G,cn,A]

n=int(input())
A=[int(input())]
for i in range(n-1):
    A.append(int(input()))
    
m,G,cnt,A=shell(A,n)
print(m)
print(*G)
print(cnt)
for i in A:
    print(i)
