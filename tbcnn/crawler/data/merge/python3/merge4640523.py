import math
inf = math.inf

def merge(A, left, mid, right):
    global cnt
    
    L = []
    R = []
    for i in A[left:mid]:
        L.append(i)
    for i in A[mid:right]:
        R.append(i)
    L.append(inf)
    R.append(inf)
    i = 0
    j = 0
    for k in range(left, right):
        cnt += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
            
        else:
            A[k] = R[j]
            j += 1

def mergeSort(A, left, right):
    if right - left > 1:
        mid = (left + right) // 2
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)

_ =input()
A = list(map(int, input().rstrip().split(" ")))
cnt = 0
mergeSort(A, 0, len(A))

print(" ".join(list(map(str, A))))
print(cnt)
    
