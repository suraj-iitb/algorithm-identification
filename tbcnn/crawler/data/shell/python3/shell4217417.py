def insertionSort(A, n, g):
    cnt=0
    for i in range(g,n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt+=1
        A[j+g] = v
    return cnt,A

def shellSort(A, n):
    cnt = 0
    
    G = [1]
    flag=True
    while flag:
        g = G[0]*3+1
        if g < n:
            G = [g] + G
        else:
            flag=False
    m = len(G)
    
    for i in range(m):
        tmp_cnt,tmp_A = insertionSort(A, n, G[i])
        cnt += tmp_cnt
    print(m)
    G_str = (list(map(lambda x:str(x),list(G))))
    print(" ".join(G_str))
    print(cnt)
    for a in A:
        print(a)
    #print(A)
    
n = int(input())
A = []
for i in range(n):
    A.append(int(input()))
shellSort(A, n)
