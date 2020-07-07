n = int(input())
S = [int(i) for i in input().split()]
infty = 10**10
cnt = 0
def merge(A, left, mid, right):
    n1 = mid - left
    n2 = right - mid
    
#     L = [0] * (n1 + 1)
#     R = [0] * (n2 + 1)
#     for i in range(n1):
#         L[i] = A[left + i]
#     for i in range(n2):
#         R[i] = A[mid + i]
# #     L = [A[left + i] for i in range(n1)]
# #     R = [A[mid + i] for i in range(n2)]

#     L[n1] = infty 
#     R[n2] = infty
    
    L = A[left:mid] + [infty]
    R = A[mid:right] + [infty]

    
    i = 0
    j = 0
    for k in range(left, right):
        global cnt
        cnt += 1
        if(L[i] <= R[j]):
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
            
def mergeSort(A, left, right):
    if (left + 1 < right):
        mid = int((left + right)/2)
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)
mergeSort(S, 0, len(S))
print(" ".join([str(st) for st in S]))
print(cnt)
