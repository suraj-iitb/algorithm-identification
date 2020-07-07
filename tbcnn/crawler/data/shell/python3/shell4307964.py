def InsertionSort(A,N,g):
    cnt=0
    for i in range(g,N):
        v=A[i]
        j=i-g
        while(j>=0 and A[j]>v):
            A[j+g]=A[j]
            j-=g
            cnt+=1
        A[j+g]=v
    return A,cnt
        # print(end='\n')
def shellSort(A,N):
    m=len(A)
    G=[1]
    fig=1
    a=0
    b=2
    while(True):
        fig=b**2*b
        # fig=fig*3+1
        if fig>m:break#超えたら
        G.append(fig)
        b+=1
    G=G[::-1]
    for i in G:
        sort,cnt=InsertionSort(A,N,i)
        a+=cnt
    print(len(G))
    for j in G:print(j,end=' ')
    print(end='\n')
    print(a)
    for k in sort:print(k,end='\n')



N=int(input())
A=[int(input()) for x in range(N)]
shellSort(A,N)
