#ALDS1_2-C Sort 1 - Shell Sort
def insertionSort(A,n,g):
    cnt=0
    i=g
    while(i<n):
        v=A[i]
        j=i-g
        while(j>=0 and A[j]>v):
            A[j+g]=A[j]
            j=j-g
            cnt+=1
        A[j+g]=v
        i+=1
    return cnt


def shellSort(A,n):
    cnt=0
    G=[]
    h=1
    m=0
    shells=""
    while h<n:
        G.insert(0,h)
        shells = " "+str(h)+shells
        h=h*3+1
        m+=1

    if(shells==""):
        print("1")
        shells=" 1"
    else:
        print(m)
    print(shells[1:])
    for i in range(m):
        cnt+=insertionSort(A,n,G[i])
    print(cnt)

n=int(input())
A=[]
for i in range(n):
    A.append(int(input()))
shellSort(A,n)
for i in range(n):
    print(A[i])
