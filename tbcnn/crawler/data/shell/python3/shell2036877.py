#coding:UTF-8
def iS(N,A,g,cnt):
    for i in range(g,N):
        v=A[i]
        j=i-g
        while j>=0 and A[j]>v:
            A[j+g]=A[j]
            j=j-g
            cnt+=1
        A[j+g]=v
    return(cnt)


def sS(N,A):
    cnt=0
    G=[]
    h=1
    while h <= N:
        G.append(h)
        h=3*h+1
    m=len(G)
    print(m)
    G.reverse()
    for i in range(m):
        cnt=iS(N,A,G[i],cnt)
    for i in range(len(G)):
        G[i]=str(G[i])
    print(" ".join(G))
    print(cnt)
    for i in range(len(A)):
        print(A[i])

        
if __name__=="__main__":
    N=int(input())
    A=[]
    for i in range(N):
        A.append(int(input()))
    sS(N,A)
