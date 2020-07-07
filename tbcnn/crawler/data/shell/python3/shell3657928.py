def insertionSort(A,n,g,cnt):
    for i in range(g,n):
        v=A[i]
        j=i-g
        while j>=0 and A[j]>v:
            A[j+g]=A[j]
            j-=g
            cnt+=1
        A[j+g]=v
    return A,cnt

def shellSort(A,n):
    cnt=0
    G=[1]
    h=1
    while h<=n//9:
        h=3*h+1
        G.append(h)
    m=len(G)
    G.reverse()

    for i in range(m):
        A,cnt=insertionSort(A,n,G[i],cnt)
    return A,G,m,cnt

if __name__=="__main__":
    n=int(input())
    A=[]
    for i in range(n):
        A.append(int(input()))
    A,G,m,cnt=shellSort(A,n)
    print(m)
    print(' '.join(map(str,G)))
    print(cnt)
    print('\n'.join(map(str,A)))
