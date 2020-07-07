num = int(input())
A = list(map(int, input().split()))
A_str = [str(a) for a in A]
print(' '.join(A_str))
for i in range(1,len(A)):
    v = A[i]
    j = i - 1
    while j >= 0 and A[j] > v:
        A[j+1] = A[j]
        j-= 1
    A[j+1] = v
    A_str = [str(a) for a in A]
    print(' '.join(A_str))
