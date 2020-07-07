n = int(input())
s = list(map(int, input().split()))
cnt = 0

def merge(A, left, mid, right):
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
            i += 1
        else:
            A[k] = R[j]
            j += 1
            
def mergeSort(A, left, right):
    if left+1 < right:
        mid = (left+right) // 2
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)
        
mergeSort(s, 0, n)
print(' '.join(map(str, s)))
print(cnt)
