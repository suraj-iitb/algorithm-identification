def show(A):
    L = list(map(str, A))
    print(" ".join(L))

N = int(input())
A = list(map(int, input().split()))

show(A)

for i in range(1, N):
    v = A[i]
    j = i - 1
    
    while j>=0 and A[j]>v:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = v
    
    show(A)
