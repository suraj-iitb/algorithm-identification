def merge(A, left, mid, right):
#    n1 = mid - left
#    n2 = right - mid
    
#    L = [0 for i in range(n1+1)]
#    R = [0 for i in range(n2+1)]

#    for i in range(n1):
#        L[i] = A[left + i]
#        
#    for i in range(n2):
#        R[i] = A[mid + i]
    
#    L[n1]=1000000001
#    R[n2]=1000000001

    L = A[left:mid] + [1000000001]
    R = A[mid:right] + [1000000001]

    cnt1 = 0
    cnt2 = 0
    
    for k in range(left, right):
        if L[cnt1] <= R[cnt2]:
            A[k] = L[cnt1]
            cnt1 += 1
        else:
            A[k] = R[cnt2]
            cnt2 +=  1
    
    global cnt
    cnt += cnt1 + cnt2
    
    
def mergeSort(A, left, right):
    if left+1 < right:
        mid = (left + right)//2
        
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)
        

n = int(input().rstrip())
A = list(map(int,input().split(" ")))
cnt = 0
mergeSort(A, 0 , len(A))
print(" ".join(list(map(str,A))))
print(str(cnt))
