N = int(input())
A  = input().split()
A = [int(x) for x in A]

c = 0 #交換回数
for i in range(N):
    minj = i
    for j in range(i,N):
        if A[j] < A[minj]:
            minj = j
    if i != minj:
        c +=1
        v = A[i]
        A[i] = A[minj]
        A[minj] = v

A = [str(x) for x in A]
print(" ".join(A))
print(c)
