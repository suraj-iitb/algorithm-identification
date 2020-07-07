n = int(input())
A = list(map(int, input().split()))
l = [str(a) for a in A]
print(" ".join(l))

for i in range(1,n):
    v = A[i]
    j = i - 1
    while j>=0 and A[j] > v:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = v
    l = [str(a) for a in A]
    print(" ".join(l))
    
