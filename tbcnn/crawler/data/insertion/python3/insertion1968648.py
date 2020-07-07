n = int(input())
A = list(map(int, input().split()))

for i, key in enumerate(A):
    j = i - 1
    while j >= 0 and A[j] > key:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = key
    
    print(" ".join(map(str, A)))
