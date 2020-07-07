def merge(A, left, mid, right):
	global count
	n1 = mid - left
	n2 = right - mid
	L=[]
	R=[]
	
#	for i in range(n1):
#		L.append(A[left + i])
#	for i in range(n2):
#		R.append(A[mid + i])
	L=A[left:mid]
	R=A[mid:right]

	L.append(10e10)
	R.append(10e10)
	i = 0
	j = 0
	for k in range(left , right):
		count +=1
		if L[i] <= R[j]:
			A[k] = L[i]
			i = i + 1
		else: 
 			A[k] = R[j]
 			j =	 j + 1

def mergeSort(A, left, right):
	if left+1 < right:
		mid = (left + right)//2
		mergeSort(A, left, mid)
		mergeSort(A, mid, right)
		merge(A, left, mid, right)
		
n = int(input())
A = list(map(int, input().split()))
count = 0
mergeSort(A, 0, n)
print(*A)
print(count)


