def CountingSort(A, k):
 C = [0] * (k+1)
 for j in A:
  C[j] += 1
 for i in range(1, k+1):
  C[i] += C[i-1]
 B = [0] *(max(C))
 for j in A[::-1]:
  B[C[j]-1] = j
  C[j] -= 1
 return B

n = int(input())
A = list(map(int, input().split()))
k = max(A)
B =CountingSort(A, k)
print(" ".join(map(str,B)))
