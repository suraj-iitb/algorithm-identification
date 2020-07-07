def merge(A, left, mid, right):
    n1 = mid - left
    n2 = right - mid
    L = A[left:mid]
    R = A[mid:right]
    L.append(10 ** 9)
    R.append(10 ** 9)
    i = 0
    j = 0
    global count
    for k in range(left, right):
        count += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

def mergeSort(A, left, right):
    if left + 1 < right:
        mid = int((left + right)/2)
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)

n = int(input())
A = list(map(int, input().split()))
count = 0
mergeSort(A, 0, n)

print(*A)
print(count)
