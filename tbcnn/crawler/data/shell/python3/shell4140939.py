
cnt = 0
def insertionSort(A, n, g):
    global cnt####スコープ指定
    for i in range(g,n):
        v = A[i]
        j = i - g
        while j >= 0 and  A[j] > v:##後半の条件が付いていてもiを回すのでソートされる
            A[j+g] = A[j]
            j = j - g
            cnt+=1
            A[j+g] = v


def shellSort(A, n):
    tmp = 1
    G=[]
    while tmp<n:
        G.append(tmp)
        tmp*=3
        tmp+=1###なぜ要るのか分からないが
    G.reverse()
    for i in range(len(G)):
        insertionSort(A, n, G[i])

n = int(input())

G1=[]
tmp=1
while tmp<n:
    G1.append(tmp)
    tmp*=3
    tmp += 1
G1.reverse()
A1 =[int(input()) for _ in range(n)]
m = len(G1)
shellSort(A1, n)
print(max(m,1))
if G1:
    print(*G1)
else:
    print(1)
print(cnt)
for a in A1:
    print(a)



