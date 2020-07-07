# def insertionsort(A,n,g):
#     global cnt
#     for i in range(g,n):
#         v = A[i]
#         j = i - g
#         while j >= 0 and A[j] > v:
#             A[j+g] = A[j]
#             j = j - g
#             cnt += 1
#         A[j+g] = v

def insertionsort(A,n,g):
    global cnt
    for i in range(g,n):
        right = i
        left = i - g
        while left >= 0 and A[left] > A[right]:
            A[right],A[left] = A[left],A[right]
            right = left
            left -= g
            cnt += 1

def shellsort(A,n):
    G = [1]
    x = 0
    while G[x]*3 + 1 <= n:
        G.append(G[x]*3 + 1)
        x += 1

    G = G[::-1]
    for i in range(len(G)):
        insertionsort(A,n,G[i])

    return A,G,cnt


if __name__ == '__main__':
    import math
    n = int(input())
    A = []
    cnt = 0
    for i in range(n):
        x = int(input())
        A.append(x)
    ans,G,cnt = shellsort(A,n)

    #answer
    print(len(G))
    for i in range(len(G)):
        if i == len(G) - 1:
            print(G[i])
        else:
            print(G[i],end = " ")
    print(cnt)
    for i in range(n):
        print(ans[i])

