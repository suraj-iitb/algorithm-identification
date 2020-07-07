def insertionSort(A, n, g):
    global cnt 

    for i in range(g,n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt+=1
        A[j+g] = v

def shellSort(A, n):
    global cnt
    cnt = 0
    g = 1
    G = [1]
    m = 1
    for i in range(1,101):
        tmp = G[i-1]+(3)**i
        if tmp <= n:
            m = i+1
            G.append(tmp)
            g += 1
        else:
            break
    G.reverse() 
    print(m)  # 1行目
    print(" ".join(list(map(str,G))))  # 2行目

    for i in range(0,m):
        insertionSort(A, n, G[i])
    print(cnt)  # 3行目
    for i in range(0,len(A)):
        print(A[i]) # 4行目以降

cnt = 0
n = int(input())
A = []
for i in range(n):
    A.append(int(input()))
shellSort(A,n)
