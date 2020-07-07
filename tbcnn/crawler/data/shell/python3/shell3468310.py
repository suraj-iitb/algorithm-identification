def insertionSort(A,N,g):
    global cnt
    for i in range(g,N):
        v = A[i]
        j = i-g
        while j >=0 and A[j] > v:
            A[j+g] = A[j]
            j -= g
            cnt += 1
        A[j+g] = v

def ShellSort():
    global cnt
    A = []
    n = int(input())
    m = 1
    G = [1]
    for i in range(1,n):
        x = 3*G[i-1]+1
        if x > n:
            break
        m += 1
        G.append(3*G[i-1]+1)
    G.reverse()
    for i in range(n):
        A.append(int(input()))
    for i in range(m):
        insertionSort(A,n,G[i])
    #if cnt > int(n**1.5)+1 :
    #    print('over!')
    print(m)
    str = ""
    for i in range(m):
        str += "{} ".format(G[i])
    print(str[:len(str)-1])
    print(cnt)
    for i in range(n):
        print(A[i])

if __name__ == '__main__':
    cnt = 0
    ShellSort()

