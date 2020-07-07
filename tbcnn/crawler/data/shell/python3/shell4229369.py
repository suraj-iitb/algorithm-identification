def insertionSort(A,n,g,count):
    for i in range(g,N):
        v = A[i]
        j = i-g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j -= g
            count += 1
        A[j+g] = v
    return count

def shellSort(A,n):
    count = 0
    m = 0
    G = []
    while (3**(m+1)-1)//2 <= n:
        m += 1
        G.append((3**m-1)//2)
    for i in range(m):
        count = insertionSort(A,n,G[-1-i],count)
    return m,G,count

import sys
input = sys.stdin.readline

N = int(input())
A = [int(input()) for _ in range(N)]

m,G,count = shellSort(A,N)

print(m)
print(*G[::-1])
print(count)
print('\n'.join(map(str,A)))
