def CountingSort(A, k):
    C = [0]*(k+1)
    n = len(A)
    
    for a in A:
      C[a] += 1
      
    for i in range(1, k+1):
      C[i] += C[i-1]
      
    B = [0]*n
    for a in A:
      B[C[a]-1] = a
      C[a] -= 1
      
    return B
    
n = int(input())
a = list(map(int, input().split()))
ans = CountingSort(a, 10000)
print(' '.join(map(str, ans)))
