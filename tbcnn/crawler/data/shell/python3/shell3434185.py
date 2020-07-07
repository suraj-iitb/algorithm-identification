def insertionSort(A, n, g):
    cnti = 0
    for i in range(g, n):
        v = A[i]
        j = i-g
        while (j >= 0 and A[j] > v):
            A[j + g] = A[j]
            j -= g
            cnti += 1
        A[j+g] = v
    return cnti
def shellSort(A,n):
    cnt = 0
    G = [1]
    h = 1
    for k in range(int(n**0.33333333)+1):
        h = 3*h + 1  ## h=1,4,13,40,121,364 ... 왜 이게 효율이 좋은지는 모르겠음(다른 사이트 봄)
        if (h <= n and len(G) < 100):
            G.append(h)
        elif(len(G) == 100):
            break    
    G.reverse()
    m = len(G)
    for i in range(m):
        cnt += insertionSort(A, n, G[i])
    print(m)
    for i in range(m):
        if (i == m-1):
            print('{}'.format(G[i]), end = '')
        else:
            print('{}'.format(G[i]), end = ' ')
    return cnt
        
        
        
n = int(input())
nlist = []
for i in range(n):
    x = int(input())
    nlist.append(x)
    
c = shellSort(nlist,n)
print()
print(c)
for i in nlist:
    print(i)
