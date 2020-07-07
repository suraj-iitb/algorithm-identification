N = int(input())
A = []
for i in range(N):
    A.append(int(input()))


def insertionSort(N,A,g):
    global cnt
    for i in range(g,N):
        v = A[i]
        j = i-g
        while A[j] > v and j >= 0:
            A[j+g] = A[j]
            j -= g
            cnt += 1
        A[j+g] = v
    return A    
      
def shellSort(N,A):
    global cnt
    cnt = 0
    m = 1
    G = [1]
    x = 1
    for i in range(N):
        x = 3*x + 1
        if x > N:
            break
        G.insert(0,x)
        m += 1
    
    for i in range(m):
        A = insertionSort(N,A,G[i])
    
    return cnt,A,m,G

cnt,A,m,G = shellSort(N,A)
print(m)
print(" ".join([str(g) for g in G]))
print(cnt)
for i in range(len(A)):
    print(A[i])
        
        
        
