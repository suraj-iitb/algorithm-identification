def merge(A, l, m, r):
    n1 = m - l
    n2 = r - m
    
    L = [A[l+i] for i in range(n1)]
    R = [A[m+i] for i in range(n2)]
    L.append(10**10)
    R.append(10**10)
    
    i = 0
    j = 0
    for k in range(l, r):
        if L[i]<=R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    global cnt
    cnt += i+j
    #print(cnt)
    return i+j
    
def mergeSort(A, l, r):
    if l+1<r:
        mid = (l + r)//2;
        mergeSort(A, l, mid)
        mergeSort(A, mid, r)
        merge(A, l, mid, r)


n = int(input())
A = list(map(int, input().split()))
#n = 10
#A = [8, 5, 9, 2, 6, 3, 7, 1, 10, 4]
cnt = 0

mergeSort(A, 0, n)
print(*A)
print(cnt)
