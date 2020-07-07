def insertSort(A,n,g):
    global cnt
    for i in range(g,N):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt +=1
        A[j+g] = v

N = int(input())
A = []
for i in range(N):
    A.append(int(input()))
cnt = 0
g = []
h = 1
while 1:
    g.append(h)
    h = 3*h+1
    if h > N:
        break
m = len(g)
for i in range(m-1,-1,-1):
    insertSort(A,N,g[i])
print(m)
g.reverse()
print(*g)
print(cnt)
for i in range(N):
    print(A[i])

