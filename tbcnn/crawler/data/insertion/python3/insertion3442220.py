N = int(input())
A = [int(i) for i in input().split()]
for i in range(1,N):
    v = A[i]
    j = i -1
    print(' '.join(map(str,A)))
    while j >=0 and A[j] > v:
        A[j+1] = A[j]
        A[j] = v
        j-=1
print(' '.join(map(str,A)))
