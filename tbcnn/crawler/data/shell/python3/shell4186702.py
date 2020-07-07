def insersionSort(A, N, count=0, g=1):
    # 間隔 g で挿入ソートを行う
    for i in range(g, N):
        v = A[i]
        j = i - g 
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j -= g
            count += 1
        A[j+g] = v
        
    return A, count

def shellSort():
    N, *A = map(int, open(0).read().split())
  
    G = [1]
    cursor = 2
    while True:
        g = (3 ** cursor - 1) // 2
        if g < N:
            G.append(g)
            cursor += 1
        else:
            break
    G = G[::-1]
    
    print(len(G))
    print(' '.join([str(g) for g in G]))
    
    count = 0
    for g in G:
        A, count = insersionSort(A, N, count, g)
    print(count)
    
    for a in A:
        print(a)
        
if __name__=="__main__":
    shellSort()
