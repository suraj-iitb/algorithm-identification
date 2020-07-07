import copy

def partition(A, p, r):
    x = A[r]
    i = p-1
    for j in range(p, r):
        if A[j][1] <= x[1]:
            i += 1
            A[i], A[j] = A[j], A[i]
            
    A[i+1], A[r] = A[r], A[i+1]
    return i + 1

def quicksort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quicksort(A, p, q-1)
        quicksort(A, q+1, r)
        
n = int(input())
S = []
for _ in range(n):
    a, b = map(str, input().split())
    S.append([a, int(b)])
copyS = copy.deepcopy(S)

quicksort(S, 0, n-1)

for i in range(n-1):
    if S[i][1] == S[i+1][1]:
        if copyS.index(S[i]) > copyS.index(S[i+1]):
            print("Not stable")
            break         
else:
    print("Stable")
    
for j in S:
    print(" ".join(str(a) for a in j))
