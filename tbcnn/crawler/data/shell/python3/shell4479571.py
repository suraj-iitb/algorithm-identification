import math

def insertionSort(A,n,g):
    cnt = 0
    for i in range(g,n):
        v = A[i]
        j = i-g
        while j >= 0 and A[j] > v:
            A[j+g], A[j] = A[j],A[j+g]
            j -= g
            cnt += 1
        A[j+g] = v
    return cnt

def shellSort(A,n):
    cnt = 0
    m = round(math.log(len(A),2))+1 # 事前処理をやる回数
    print(m)
    G = [round(len(A)*((1/2)**(a+1))) for a in range(m)] # 事前処理時の、各回の間隔
    print(*G)
    for i in range(0,m):
        cnt += insertionSort(A,n,G[i])
    return cnt

n = int(input())
A = [int(input()) for a in range(n)]
print(shellSort(A,n))
for a in A:
    print(a)

