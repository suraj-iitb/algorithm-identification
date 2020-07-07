N = int(input())
A = input().split()
print(" ".join(A))
A = [int(l) for l in A]
for i in range(1,N):
    v = A[i]
    j = i-1
    while j>=0 and A[j] >v:
        A[j+1] = A[j]
        j -=1
    A[j+1] = v
    A = [str(l) for l in A]
    print(" ".join(A))
    A = [int(l) for l in A]
