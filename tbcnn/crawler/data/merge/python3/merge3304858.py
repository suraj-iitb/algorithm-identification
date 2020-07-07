import sys
n = int(input())
s = list(map(int, input().split()))
c = 0
a = 'a'
def merge(A, left, mid, right):
    global c
    L = A[left:mid]
    R = A[mid:right]
    L.append(sys.maxsize)
    R.append(sys.maxsize)
    i = 0
    j = 0
    for k in range(left, right):
        c += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

def mergesort(A, left, right):
    if left+1 < right:
        mid = (left+right)//2
        mergesort(A, left, mid)
        mergesort(A, mid, right)
        merge(A, left, mid, right)

mergesort(s, 0, n)

for i in range(n-1):
    print(s[i], end=' ')
print(s[n-1])
print(c)
