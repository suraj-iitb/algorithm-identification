# coding: utf-8
# Your code here!
INF = 10000000000

def merge(A, left, mid, right):
    global ctr

    L = A[left:mid] + [INF]
    R = A[mid:right] + [INF]
    i,j = 0,0
    for k in range(left,right):
        ctr += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

def mergeSort(A, left, right):
    if left+1 < right:
        mid = (left + right) // 2
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A, left, mid, right)
        

n = int(input())
A = list(map(int,input().split()))
ctr = 0

mergeSort(A,0,n)

print(*A)
print(ctr)
