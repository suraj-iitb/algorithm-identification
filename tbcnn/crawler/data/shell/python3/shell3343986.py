def InsertionSort(A, n, g):
    global count
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            count += 1
        A[j+g] = v

def ShellSort(A, n):
    G =[1]
    while True:
        g = 3*G[0] + 1
        if g > n:
            break
        G.insert(0, g)
    m = len(G)
    for i in range(m):
        InsertionSort(A, n, G[i])
    return [m, G]

N = int(input())

A = [int(input()) for i in range(N)]
count = 0
m, G = ShellSort(A, N)
print(m)
print(*G)
print(count)
for i in A:
    print(i)
