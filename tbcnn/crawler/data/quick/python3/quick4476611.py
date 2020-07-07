# INF = 10*10

def partition(A, p, r):
   x = A[r][1]
   i = p-1
   for j in range(p, r):
     if A[j][1] <= x:
       i = i+1
       A[i], A[j] =  A[j], A[i]
   A[i+1] , A[r] = A[r], A[i+1]
   return i+1

def quicksort(A, p, r):
   if p < r:
     q = partition(A, p, r)
     quicksort(A, p, q-1)
     quicksort(A, q+1, r)
#
# def merge(A, left, mid,  right):
#   global cnt
#   L = A[left:mid]
#   L.append([0,INF])
#   R = A[mid:right]
#   R.append([0,INF])
#   i = 0
#   j = 0
#   for k  in range(left , right):
#     if L[i][1] <= R[j][1]:
#       A[k] = L[i]
#       i = i + 1
#     else:
#       A[k] = R[j]
#       j = j + 1
#
# def mergeSort(A, left, right):
#   if left+1 < right:
#     mid = (left + right)//2
#     mergeSort(A, left, mid)
#     mergeSort(A, mid, right)
#     merge(A, left, mid, right)
#
n = int(input())
A = [[0 for j in range(3)] for i in range(n)]
# B = [[0 for j in range(2)] for i in range(n)]
for i in range(n):
    A[i][0],A[i][1] = input().split()
    A[i][1] = int(A[i][1])
    A[i][2] = i
    # B[i][1] = int(B[i][1])

quicksort(A, 0, n-1)
# mergeSort(B, 0, n)
#
# if A == B:
#     print("Stable")
# else:
#     print("Not stable")

stable_FLG = True
for i in range(1,n):
    if A[i][1] == A[i-1][1] and A[i][2] < A[i-1][2]:
        stable_FLG = False
        break

if stable_FLG:
    print("Stable")
else:
    print("Not stable")


for i in range(n):
    print(A[i][0],A[i][1])


