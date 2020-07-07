def mergeSort(A,left,right,B):
    if left + 1 < right:
        mid = (left+right)//2
        mergeSort(A,left,mid,B)
        mergeSort(A,mid,right,B)
        merge(A,left,mid,right,B)

def merge(A,left,mid,right,B):
    L = A[left:mid]
    R = A[mid:right]
    L.append(1000000000)
    R.append(1000000000)

    i = 0
    j = 0
    for k in range(left,right):
        B.append(1)
        if L[i] < R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

n = int(input())
nums = list(map(int,input().split(" ")))
B = []

mergeSort(nums,0,n,B)
print(' '.join(map(str,nums)))
print(str(len(B)))

