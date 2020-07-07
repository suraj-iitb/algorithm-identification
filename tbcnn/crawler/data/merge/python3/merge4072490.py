"""
マージソートを実装する
"""
count = 0

def merge(A, left, mid, right):
    global count

    n1 = mid-left
    n2 = right-mid

    L = [0]*(n1+1)
    for i in range(n1):
        L[i] = A[left+i]
    
    R = [0]*(n2+1)
    for i in range(n2):
        R[i] = A[mid+i]
    
    L[n1] = 10000000000
    R[n2] = 10000000000

    i, j = 0, 0 
    for k in range(left, right):
        count += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i = i+1
        else:
            A[k] = R[j]
            j = j+1
    return count
    
def mergeSort(A, left, right):
    if left+1 < right:
        mid = (left+right)//2
        #sortする
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        #統合する
        merge(A, left, mid ,right)


n = int(input())
s = list(map(int, input().split()))
mergeSort(s, 0, n)
s = map(str, s)
print(' '.join(s))
print(count)
    
