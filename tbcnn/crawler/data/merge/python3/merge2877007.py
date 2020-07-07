count=0
def merge(A, left, mid, right):
    global count
    L=A[left:mid]+[2**32]
    R=A[mid:right]+[2**32]
    i=0
    j=0
    for k in range(left,right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
        count+=1
def merge_sort(A, left, right):
    if left+1 < right:
        mid=(left+right)//2
        merge_sort(A, left, mid)
        merge_sort(A, mid, right)
        merge(A, left, mid, right) 

if __name__ == "__main__":
    n=int(input())
    A=list(map(int,input().split()))
    merge_sort(A,0,n)
    print(*A)
    print(count)
