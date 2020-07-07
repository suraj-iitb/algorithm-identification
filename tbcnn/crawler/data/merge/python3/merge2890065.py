cnt = 0
def merge(S,left,right,mid):
    a = mid - left
    b = right - mid
    L = S[left:left+a]+[float("inf")]
    R = S[mid:mid+b]+[float("inf")]
    j = 0
    k = 0
    for i in range(left,right):
        global cnt
        cnt+=1
        if L[j] <= R[k]:
            S[i] = L[j]
            j += 1
        else:
            S[i] = R[k]
            k += 1
            
def mergeSort(S,left,right):
    if left+1<right:
        mid = (int)((left+right)/2)
        mergeSort(S,left,mid)
        mergeSort(S,mid,right)
        merge(S,left,right,mid)
        
n = int(input())
S = list(map(int, input().split()))
mergeSort(S,0,n)
print(*S)
print(cnt)
