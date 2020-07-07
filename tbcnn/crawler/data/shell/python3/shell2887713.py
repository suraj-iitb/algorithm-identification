import math
n = int(input())
li = [int(input()) for i in range(n)]
cnt = 0
def shell_sort(li, n):
    m = math.floor(math.log(2*n+1, 3))
    G = [round((3**i-1)/2) for i in range(m, 0, -1)]
    for i in range(m):
        insertionSort(li, n, G[i])
    return m, G
def insertionSort(A, n, g):
    global cnt
    for i in range(g, n):
        v = A[i]
        j = i-g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j-g
            cnt += 1
        A[j+g] = v

m, G = shell_sort(li, n)

print(m)
strG = [str(i) for i in G]
print(' '.join(strG))
print(cnt)
for i in li:
    print(i)
