N = int(input())
A = [int(n) for n in input().split()]

c = 0

for i in range(N):
    minj = i
    for j in range(i,N):
        if A[j] < A[minj]:
            minj = j

    if  A[i] !=  A[minj]:
        c += 1
        A[i], A[minj] = A[minj],A[i]
    

print(" ".join([str(a) for a in A]))
print(c)
