import copy
n = int(input())
A = []
for ni in range(n):
    A.append(input().split())
B = copy.deepcopy(A)
B.sort(key = lambda x: int(x[1]))

def Partition(A, p, r):
    i = p - 1
    for j in range(p, r):
        if int(A[j][1]) <= int(A[r][1]):
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i+1], A[r] = A[r], A[i+1]
    return i+1, A

def QuickSort(A, p, r):
    if p >= r:
        return None
    else:
        q, A = Partition(A, p, r)
        QuickSort(A, p, q-1)
        QuickSort(A, q+1, r)
        return A

QuickSort(A, 0, n-1)
if A == B:
    print("Stable")
else:
    print("Not stable")
for ni in range(n):
    print(*A[ni], sep=" ")

