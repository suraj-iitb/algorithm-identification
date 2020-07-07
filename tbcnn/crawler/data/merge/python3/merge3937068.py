n = int(input())
A = list(map(int, input().split()))
count = 0
def Merge(A, left, mid, right):
    global count
    L = A[left:mid]+[10**9]
    R = A[mid:right]+[10**9]

    i = 0
    j = 0

    for k in range(left, right):
        count += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

def MergeSort(A, left, right):
    if left+1 < right:
        mid = (left+right)//2
        MergeSort(A, left, mid)
        MergeSort(A, mid, right)
        Merge(A, left, mid, right)

MergeSort(A, 0, n)
print(' '.join([str(_) for _ in A]))
print(count)


