n = int(input())
A = [int(input()) for _ in range(n)]
G = [1]
a=1
while True:
    a = 3*a+1
    if a>=n:
        break
    G.append(a)
if len(G)>1:
    G.sort(reverse=True)
m = len(G)
cnt = 0

def shellSort(A,n):
    cccnt = 0
    for k in range(m):
        cccnt += insertionSort(A,n,G[k])
    return cccnt

def insertionSort(A,n,g): #Aはリスト　nは要素数　gは間隔
    ccnt = 0
    for i in range(g,n):
        v = A[i]
        j = i-g
        while j>=0 and A[j] > v:
            A[j+g] = A[j]
            j -= g
            ccnt += 1
        A[j+g] = v
    return ccnt

cnt = shellSort(A,n)

print(m)
print(' '.join(map(str,G)))
print(cnt)
for _ in range(n):
    print(A[_])
