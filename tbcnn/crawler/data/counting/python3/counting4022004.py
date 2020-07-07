

def CountingSort(A, B, k, n):
    C = []
    for i in range(k + 1):
        C.append(0)
        
    for i in range(n):
        B.append(0)
        
    for i in range(n):
        C[A[i]] += 1
    
    for i in range(1, k + 1):
        C[i] = C[i] + C[i-1]
        

    for i in range(n-1, -1, -1):
        B[C[A[i]]-1] = A[i]
        C[A[i]] -= 1
        
n = int(input())
A = list(map(int, input().split())) 
B = []
k = max(A)
CountingSort(A, B, k, n)
for i in range(n-1):
    print(B[i], end = " ")
print(B[n-1])



