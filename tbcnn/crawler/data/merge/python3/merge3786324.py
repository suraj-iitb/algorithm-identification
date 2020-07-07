def merge(A, left, mid, right, c):
    global counter
    n1 = mid - left
    n2 = right - mid
    L = [0] * (n1+1)
    R = [0] * (n2+1)
    for i in range(n1):
        L[i] = A[left + i]
    for i in range(n2):
        R[i] = A[mid + i]
    L[n1] = 1000000000
    R[n2] = 1000000000
    i = 0
    j = 0
    for k in range(left,right):
        c += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else : 
            A[k] = R[j]
            j += 1
    L.pop()
    R.pop()
    return c

def mergeSort(A, left, right, c):
    if left+1 < right:
        mid = int((left + right)/2)
        c = mergeSort(A, left, mid, c)
        c = mergeSort(A, mid, right, c)
        c = merge(A, left, mid, right, c)
    return c

if __name__ == '__main__':
    num = int(input())
    m = list(map(int,input().split()))
    c = 0
    c = mergeSort(m, 0, num, c)
    print(' '.join(map(str,m)))
    print(str(c))
