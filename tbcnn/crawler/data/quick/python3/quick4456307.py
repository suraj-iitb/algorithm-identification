import sys

def partition(A, p, r):
    x = A[r]
    i = p-1
    for j in range(p,r):
        if A[j][1] <= x[1]:
            i = i+1
            A[i], A[j] = A[j], A[i]
    A[i+1], A[r] = A[r], A[i+1]
    return A, i+1

def quickSort(A, p, r):
    if p < r:
        A, q = partition(A, p, r)
        A = quickSort(A, p, q-1)
        A = quickSort(A, q+1, r)
    return A

N = int(input())
A = []
D = {}
for i in range(N):
    v, d = sys.stdin.readline().split()
    A.append((v, int(d)))
    D.setdefault(int(d), []).append(v)
    
out_A = quickSort(A,0,N-1)

D = {k: iter(v).__next__ for k, v in D.items()}

ok = 1
for v, d in A:
    if D[d]() != v:
        ok = 0
                
if ok:
    print("Stable")
else:
    print("Not stable")

for i in range(N):
    print(*out_A[i],sep=" ")
