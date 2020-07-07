N = int(input())
A = input().split()
print(' '.join(A))
A = [int(s) for s in A]
while A != sorted(A):
    for i in range(1, N):
        tmp = A[i]
        if A[i-1] > tmp:
            j = i
            while j >0 and A[j-1] > tmp:
                A[j] = A[j-1]
                j -= 1
            A[j] = tmp
        result = map(str, A)
        print(' '.join(result))

