cnt = 0

def merge(A, left, mid, right):
    global cnt

    L = A[left:mid]
    R = A[mid:right]
    L.append(10000000000)
    R.append(10000000000)

    i = 0
    j = 0
    for k in range(left, right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
        cnt += 1

def mergesort(A, left, right):
    if left + 1 < right: #if block size >= 2
        mid = int((left + right)/2)
        mergesort(A, left, mid)
        mergesort(A, mid, right)
        merge(A, left, mid, right)
        

n = int(input())
S = list(map(int,input().split()))
mergesort(S, 0, n)
print(*S)
print(str(cnt))
