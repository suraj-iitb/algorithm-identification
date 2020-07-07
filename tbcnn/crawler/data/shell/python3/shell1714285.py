#coding: UTF-8

cnt = 0

def SelectionSort(A,N,G):
    global cnt
    for i in range(G,N):
        v = A[i]
        j = i - G
        while j >= 0 and A[j] > v:
            A[j + G] = A[j]
            j = j - G
            cnt += 1
        A[j + G] = v
        

def ShellSort(A,N):
    G = [None] * 20
    cnt = 0
    
    for i in range(1,21):
        G[i - 1] = int(((3 ** i) - 1) / 2)
    for i in range(1,21):
        if N < G[i - 1]:
            m = i - 2
            break
    for i in range(m,-1,-1):
        SelectionSort(A,N,G[i])
    
    print(str(m+1))
    for i in range(m,0,- 1):
        print(str(G[i]) + " ", end = "")
    print(G[0])


N = int(input())
A = [None] * N
for i in range(N):
    A[i] = int(input())


ShellSort(A,N)

print(cnt)
for i in range(N):
    print(A[i])
