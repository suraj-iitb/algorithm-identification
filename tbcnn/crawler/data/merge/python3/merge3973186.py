#ALDS1_5_B
sum = 0

def merge(A, left, mid, right):
    global sum
    n1 = mid - left
    n2 = right - mid
    L = [0] * (n1+1)
#     L = A[left:mid]
    R = [0] * (n2+1)
#     R = A[mid:right]
    for i in range(n1):
        L[i] = A[left + i]
    for i in range(n2):
        R[i] = A[mid + i]
    L[n1] = 10**9
#     L.append(10**9)
    R[n2] = 10**9
#     R.append(10**9)
    i = 0
    j = 0
    for k in range(left, right):
        sum += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
            
def mergeSort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)
        
n = int(input())
S = list(map(int, input().split()))

mergeSort(S, 0, len(S))
print(*S)
print(sum)
