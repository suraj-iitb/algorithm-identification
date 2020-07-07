N   = int(input())
A   = [int(temp) for temp in input().split()]
cou = 0

for mak in range(1,N) :
    for j in range(mak,N)[ : : -1] :
        if A[j] < A[j - 1] :
            tem      = int(A[j])
            A[j]     = int(A[j - 1])
            A[j - 1] = int(tem)
            cou = cou + 1
A   = [str(temp) for temp in A]
print(' '.join(A))
print(cou)
