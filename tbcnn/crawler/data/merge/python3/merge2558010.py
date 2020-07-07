cnt = 0
def merge(A,left,mid,right):
	'''n1 = mid - left
	n2 = right - mid
	L = []
	R = []
	for i in range(0,n1):
		L.append(A[left+i])

	for i in range(0,n2):
		R.append(A[mid+i])
	L.append(1000000001)
	R.append(1000000001)
	'''
	L = A[left:mid]+[1000000001]
	R = A[mid:right]+[1000000001]

	i = 0
	j = 0
	global cnt
	for k in range(left,right):
		cnt += 1
		if L[i] <= R[j]:
			A[k]=L[i]
			i += 1
		else:
			A[k] = R[j]
			j += 1

def mergeSort(A,left,right):
	if left+1 < right:
		mid = (left+right)//2
		mergeSort(A,left,mid)
		mergeSort(A,mid,right)
		merge(A,left,mid,right)


if __name__ == '__main__':
	n = (int)(input())
	a = list(map(int,input().split()))
	
	mergeSort(a,0,n)
	print(*a)
	print(cnt)
