def insertion_sort(A,n,g):
    cnt = 0
    for i in range(g,n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        
        A[j + g] = v
    
    return cnt

def shell_sort(A,n):
    cnt = 0
    
    G = []
    val = 1
    while True:
        G.append(val)
        val = (3 * val) + 1
        if val > (n // 3) + 1:
            break
    
    G.reverse()
    m = len(G)

    for g in G:
        cnt += insertion_sort(A,n,g)

    #output
    print(m)
    print(*G)
    print(cnt)
    for a in A:
        print(a)

n = int(input())
#print(f"#dbg n:{n}")
A = []
for i in range(n):
    A.append(int(input()))

#print("#dbg A:",*A)

shell_sort(A,n)



    
    



