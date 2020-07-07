def shellSort(A,N):
    cnt = 0
    G = []
    h = 1
    while h<=N:
        G.append(h)
        h = 3*h +1

    for i in range(0, len(G)):
        cnt = cnt + insertionSort(A, N, G[len(G)-i-1])

    print(len(G))
    for i in range(len(G)):
        print(G[len(G)-i-1], end=" ")
    print()
    print(cnt)
    for i in range(N):
        print(A[i])

def insertionSort(A, N, g):
    cnt = 0
    for i in range(g, N):
        v = A[i]
        j = i - g
        while j>= 0 and A[j]>v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v
    return cnt

listnum=[]
n = int(input())
for i in range(n):
    listnum.append(int(input()))

shellSort(listnum, n)

