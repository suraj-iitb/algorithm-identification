SENTINEL = 2 ** 32
cnt = 0
def merge(A, left, mid, right):
    L = A[left:mid] + [SENTINEL]
    R = A[mid:right] + [SENTINEL]
    
    i = 0
    j = 0
    for k in range(left, right):
        global cnt
        cnt += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

def merge_sort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        merge_sort(A, left, mid)
        merge_sort(A, mid, right)
        merge(A, left, mid, right)

n = input()
A = list(map(int, input().split()))
merge_sort(A,0,len(A))
print(*A)
print(cnt)
