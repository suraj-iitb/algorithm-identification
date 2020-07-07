def insertionSort(A,g):
    global cnt
    
    for i in range(g,len(A)):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v
            
def shellSort(A):
    global cnt
    cnt = 0
    h = 1
    g = []
    while h <= len(A):
        g.append(h)
        h = 3*h+1
    g.reverse()
    m = len(g)
    print(m)
    print(' '.join(map(str,g)))
    for i in range(m):
        insertionSort(A,g[i])

    

n = int(input())
A = [int(input()) for i in range(n)] 


shellSort(A)
print(cnt)
for i in A:
    print(i)
            
