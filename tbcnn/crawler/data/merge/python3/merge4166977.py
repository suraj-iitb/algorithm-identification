def merge(A,left,mid,right):
    INF = 10**9
    n1 = mid - left
    n2 = right - mid
    #L[0…n1], R[0…n2]を生成
    L = A[left:left+n1]
    R = A[mid:mid+n2]
    L.append(INF)
    R.append(INF)
    i = 0
    j = 0
    c = 0
    for k in range(left,right):
        c += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    return c

def mergeSort(A,left,right):
    if left+1 < right:
        mid = (left+right)//2
        cL = mergeSort(A,left,mid)
        cR = mergeSort(A,mid,right)
        return merge(A,left,mid,right)+cL+cR
    return 0

N = int(input())
S = list(map(int,input().split()))
c = mergeSort(S,0,N)
print(' '.join(map(str,S)))
print(c)

