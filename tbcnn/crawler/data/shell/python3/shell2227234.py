import math
def InsertionSort(A, N, g):
    global cnt
    for i in range(g, N):
        key = A[i]
        j = i-g
        while j >= 0 and A[j] > key:
            A[j+g] = A[j]
            j = j-g
            cnt += 1    
        A[j+g] = key
    return A

def ShellSort(A, N):
    G = []
    i = 1
    while True:
        if  3**i -1 > N*2:
            break
        G.insert(0, int((3**i-1)/2))
        i += 1


    for i in range(len(G)):
        InsertionSort(A, N, G[i])
    return G

N = int(input())
A = []
cnt = 0
for i in range(N):
    A.append(int(input()))
ShellSort(A,N)
print(len(ShellSort(A,N)))
print(*ShellSort(A,N))
print(cnt)
print(*A, sep='\n')
