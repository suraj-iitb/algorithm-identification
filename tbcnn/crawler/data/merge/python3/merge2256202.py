def merge(A, left, mid, right):

    n1 = mid-left
    n2 = right-mid
    #L = [0 for i in range(n1+1)]
    #R = [0 for i in range(n2+1)]
    #for i in range(n1):
    #    L[i] = A[left+i]
    #for i in range(n2):
    #    R[i] = A[mid+i]
    L = A[left:mid]
    R = A[mid:right]
    L.append(float('inf'))
    R.append(float('inf'))
    i = 0
    j = 0
    global cnt

    for k in range(left, right):
        cnt += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i = i+1
        
        else:
            A[k] = R[j]
            j = j+1
    return cnt

def mergeSort(A, left, right):
    if left+1 < right:
         mid = (left+right) // 2
         mergeSort(A, left, mid)
         mergeSort(A, mid, right)
         merge(A, left, mid, right)
    else:
        return 0

n = input()
A = list(map(int, input().split()))
cnt = 0
mergeSort(A, 0, len(A))
print(*A)
print(str(cnt))
