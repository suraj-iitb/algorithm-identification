

INF = 10000000000
count = 0

def merge(A, left, mid, right):
    global count 
    L = A[left:mid] + [INF]
    R = A[mid:right] + [INF]
      
    i, j = 0, 0
    for k in range(left, right):
        count = count + 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i = i + 1
        else:
            A[k] = R[j]
            j = j + 1
    return count
  
def mergeSort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        countL = mergeSort(A, left, mid)
        countR = mergeSort(A, mid, right)
        return merge(A, left, mid, right)
         
    return 0
          
  
n = int(input())
A = [int(i) for i in input().split()]
#A = list(np.round(np.random.rand(n)*10,0))
count = mergeSort(A, 0, n)
print(*A)
print(count)
