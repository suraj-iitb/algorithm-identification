cnt=0
def merge(A, left, mid, right):
    n1 = mid - left
    n2 = right - mid
    inf=100000000001
    global cnt
    L=A[left:mid]+[inf]
    R=A[mid:right]+[inf]
    i = 0
    j = 0
    for k in range(left,right):
        cnt+=1
        if L[i] <= R[j]:
            A[k] = L[i]
            i = i + 1
        else:
            A[k] = R[j]
            j = j + 1

def mergeSort(A, left, right):
    if left+1 < right:
        mid = (left + right)//2;
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)

n=int(input())
S=list(map(int,input().split()))
cnt=0
left=0
right=n

mergeSort(S,left,right)
print(*S)
print(cnt)

