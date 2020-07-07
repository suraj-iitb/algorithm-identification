N = int(input())
A = list(map(int,input().split()))

for i in range(len(A)):
    V = A[i]
    j = i - 1
    while j >= 0 and A[j] > V:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = V
    print(' '.join(map(str,A)))

