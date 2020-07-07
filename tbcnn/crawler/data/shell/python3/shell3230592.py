def insertionSort(A, n, g):
    for i in range(n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt[0] += 1
        A[j+g] = v
    return cnt

def shellSort(A, n):
    # make the list of G
    h = 1
    G = [1]
    while h*3+1 < n:
        h = h*3+1
        G.append(h)
    G.reverse()
    print(len(G))
    print(*G)
    for g in range(len(G)):
        insertionSort(A, n, G[g])
        
n = int(input())
'''A = []
for i in range(n):
    inpu = int(input())
    A.append(inpu)'''
A = [int(input()) for i in range(n)]

cnt = [0]
shellSort(A,n)

print(cnt[0])
for a in A:
    print(a)
