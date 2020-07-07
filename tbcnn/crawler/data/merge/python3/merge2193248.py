from collections import deque
SENIAL = 10**9
count = 0

def merge(A,left,mid,right):
    L = deque(A[left:mid])
    R = deque(A[mid:right])
    L.append(SENIAL)
    R.append(SENIAL)
    
    global count
    
    for k in range(left,right):
        count +=1
        if L[0] <= R[0]:
            A[k] = L.popleft()
 
        else:
            A[k] = R.popleft()

            
def mergeSort(A,left,right):
    if left + 1 < right:
        middle = (left + right) //2
        mergeSort(A,left,middle)
        mergeSort(A,middle,right)
        merge(A,left,middle,right)
        
input()
l = list(map(int,input().split()))
mergeSort(l,0,len(l))
print(" ".join(map(str,l)))
print(count)            
        
