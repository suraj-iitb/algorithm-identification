N, *A = map(int, open(0).read().split())
print(*A)

for i, a in enumerate(A):
    if i == 0:
        continue
    
    j = i-1
    while j >= 0 and A[j]>a:
        A[j], A[j+1] = a, A[j]
        j -= 1
    
    print(*A)

