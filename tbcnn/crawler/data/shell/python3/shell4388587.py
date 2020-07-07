cnt=0
def insertion_sort(A, g):
    global cnt
    N=len(A)
    for i in range(g,N):
        v=A[i]
        j=i-g
        while j>=0 and A[j]>v:
            A[j+g]=A[j]
            j-=g
            cnt+=1
        A[j+g]=v
def shell_sort(A):
    G=[]
    i=1
    while i<=len(A):
        G.append(i)
        i=i*3+1
    G=G[::-1]
    for g in G:
        insertion_sort(A, g)
    return G
N=int(input())
A=[int(input()) for _ in range(N)]
G=shell_sort(A)
print(len(G))
print(*G)
print(cnt)
for a in A:
    print(a)
