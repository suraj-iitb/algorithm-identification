def Partition(A,p,r): ## r = n-1 (A의 p~r번째(0 base)요소를 partition!)
    x = A[r][1]
    i = p-1
    for j in range(p,r):
        if (A[j][1] <= x):
            i += 1
            A[i], A[j] = A[j], A[i]
    A[r], A[i+1] = A[i+1], A[r]
    return i+1

def Quicksort(A, p, r):
    if (p < r):
        q = Partition(A,p,r)
        Quicksort(A,p,q-1)
        Quicksort(A,q+1,r)
n = int(input())
A = []
color = [[]for i in range(4)] #S H C D
for i in range(n):
    a,v = input().split()
    v = int(v)
    A.append((a,v))
copya = A[:]
Quicksort(A, 0, n-1)
Avdic = dict()
for a,v in A:
    if (v not in Avdic.keys()):
        Avdic[v] = [a]
    else:
        Avdic[v] += [a]
cvdic = dict()
for a,v in copya:
    if (v not in cvdic.keys()):
        cvdic[v] = [a]
    else:
        cvdic[v] += [a]
if (Avdic == cvdic):
    print('Stable')
else:
    print('Not stable')
for a in A:
    print(*a)
