n = int(input())
A = []
for i in range(n):
    A.append(int(input()))

def InsertionSort(A,g):
    n = len(A)
    global cnt
    for i in range(g,n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j -= g
            cnt += 1
        A[j+g] = v

def ShellSort(A):
    global cnt
    cnt = 0
    Grev = []
    g = 1
    while g < n:
        Grev.append(g)
        g = 3*g + 1
    m = len(Grev)
    G = []
    for i in range(m):
        G.append(Grev[m-i-1])
    for i in range(m):
        InsertionSort(A,G[i])
    print(m)
    for k in range(m-1):
        print(G[k], end = " ")
    print(G[m-1])
    print(cnt)
    for i in range(n):
        print(A[i])

if n > 1:
    ShellSort(A)
else:
    print(1)
    print(1)
    print(0)
    print(A[0])

