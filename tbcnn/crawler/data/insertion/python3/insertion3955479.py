N = int(input())
A = [int(x) for x in input().split()]
A_str = [str(a) for a in A]
print(" ".join(A_str))

for i in range(1, N):
    j = i-1
    while A[i] < A[j] and j >=0:
        A[j], A[i] = A[i], A[j]
        j -= 1
        i -= 1
    A_str = [str(a) for a in A]
    print(" ".join(A_str))
