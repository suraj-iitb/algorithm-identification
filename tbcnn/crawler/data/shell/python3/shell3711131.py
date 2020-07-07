from sys import stdin
N = int(stdin.readline().rstrip())
A = [int(stdin.readline().rstrip()) for _ in range(N)]

def insertion_sort(a, n, g, count):
    for i in range(g, n):
        v = a[i]
        j = i - g
        while j >= 0 and a[j] > v:
            a[j+g] = a[j]
            j = j - g
            count += 1
        a[j+g] = v

    return a, count

def shell_sort(a, n, m, G):
    count = 0
    for i in range(100):
        if i == 0:
            G[i] = n//2+1
        else:
            G[i] = G[i-1]//2-1
        if G[i] < 0:
            G[i-1] = 1
            G[i] = 0
            m = i
            break
    for i in range(m):
        a, count = insertion_sort(a, n , G[i], count)
    
    return a, count, m , G

G = [0]*100
m = 0
A, count, m, G = shell_sort(A, N, m, G)
print(m)
for i in range(m):
    if i == m-1:
        print(G[i])
    else:
        print(G[i], end=" ")
print(count)
for i in range(N):
    print(A[i])
