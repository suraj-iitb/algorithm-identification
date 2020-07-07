def merge(A, left, mid, right):
    count =0
    L = A[left:mid]
    R = A[mid:right]
    L.append(float('inf'))
    R.append(float('inf'))
    i = 0
    j = 0
    for k in range(left, right):
        count +=1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    return count

def MergeSort(A, left, right):
    if left +1 < right:
        mid = (left + right)//2
        countR = MergeSort(A, left, mid)
        countL = MergeSort(A, mid, right)
        return merge(A, left, mid, right) + countL + countR
    return 0

N = int(input())
A = list(map(int, input().split()))
count = MergeSort(A, 0, N)
print(" ".join(list(map(str, A))))
print(count)
