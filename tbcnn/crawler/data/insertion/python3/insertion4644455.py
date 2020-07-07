n = int(input())
A = list(map(int, input().split()))
AS = [str(i) for i in A]
print(' '.join(AS))
for i in range(1, n):
    v = A[i]
    j = i - 1
    while j >= 0 and A[j] > v:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = v
    AS = [str(i) for i in A]
    print(' '.join(AS))
