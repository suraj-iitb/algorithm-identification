def InsertionSort(A, N, g, cnt):
    for i in range(g, N):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j -= g
            cnt += 1
        A[j+g] = v

    return(A, cnt)

def ShellSort(A, n):
    cnt = 0
    for i in range(m):
        A, cnt = InsertionSort(A , n, G[i], cnt)
    
    return(A, cnt)

n = int(input())
A = []

G = []
g = 1
while g <= n:
    G.append(g)
    g = g*3 + 1
G.reverse()
m = len(G)


for i in range(n):
    a = int(input())
    A.append(a)

A, c = ShellSort(A, n)

print(m)
print(' '.join(map(str, G)))
print(c)
for i in range(n):
    print(A[i])
