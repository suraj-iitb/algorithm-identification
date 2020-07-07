input()
*A, = map(int, input().split())

for i, a in enumerate(A):
    j = i - 1
    while j >= 0 and a < A[j]:
        A[j + 1] = A[j]
        j -= 1
    else:
        A[j + 1] = a
        print(*A)
    
    
