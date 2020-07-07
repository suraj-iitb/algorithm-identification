def partition(A, p, r):
    x = A[r][1]
    i = p-1
    for j in range(p,r):
        if A[j][1] <= x:
            i = i+1
            A[i],A[j] = A[j],A[i]
    A[i+1],A[r] = A[r],A[i+1]
    return i+1

def quickSort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quickSort(A, p, q-1)
        quickSort(A, q+1, r)
    return None
        
n = int(input())
A = [(i,int(j)) for i,j in [input().split() for i in range(n)]]
B = A.copy()
quickSort(A,0,n-1)
num = A[0][1]
pos = B.index(A[0])
ans = "Stable"
for i in A[1:]:
    if i[1] != num:
        num = i[1]
        pos = B.index(i)
    else:
        if pos > B.index(i):
            ans = "Not stable"
            break
        else:
            pos = B.index(i)
print(ans)
for i,j in A:
    print(i,j)
