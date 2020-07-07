def partition(A,p,r):
    x = int(A[r][2:])
    i = p-1
    for j in range(p,r):
        if int(A[j][2:]) <= x:
            i = i + 1
            A[i],A[j] = A[j],A[i]
    A[i+1],A[r] = A[r],A[i+1]
    return i + 1
    
def quicksort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quicksort(A, p, q-1)
        quicksort(A, q+1, r)


    
n = int(input())
A = [input() for i in range(n)]
stable = sorted(A, key=lambda x:
int(x.split()[1]))
B = A[:]
quicksort(A,0,n-1)
print("Stable" if stable == A else "Not stable")

for c in A:
    print(c)
