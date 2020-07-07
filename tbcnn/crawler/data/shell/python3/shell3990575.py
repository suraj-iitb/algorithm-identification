n = int(input())
A = list(int(input()) for _ in range(n))

def insertionSort(A, g):
    global cnt
    for i in range(g, len(A)):
        temp = A[i]
        j = i - g
        
        while j >= 0 and A[j] > temp:
            A[j+g] = A[j]
            j -= g
            A[j+g] = temp
            cnt += 1

def shellSort(A):
    global cnt
    cnt = 0
    G = []
    i = 1
    
    while i <= len(A):
        G.append(i)
        i = 3 * i + 1
        
    G.reverse()
    m = len(G)
    print(m)
    print(*G)
    
    for j in range(m):
        insertionSort(A, G[j])
        
        
shellSort(A)
print(cnt)

for a in A:
    print(a)
