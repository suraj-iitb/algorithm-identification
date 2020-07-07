
INF = 10000000000

def merge(A,left,mid,right):

	n1 = mid - left
	n2 = right - mid

	L = A[left:mid] + [INF]
	R = A[mid:right] + [INF]
	for i in range(n1):
		L[i] = A[left + i]

	for i in range(n2):
		R[i] = A[mid + i]

	i = 0
	j = 0
	cnt = 0
	for k in range(left,right):
		cnt += 1
		if L[i] <= R[j]:
			A[k] = L[i]
			i += 1
		else:
			A[k] = R[j]
			j += 1

	return cnt

def mergeSort(A,left,right):

	if left+1 < right:
		mid = ( left + right ) // 2
		cnt_l = mergeSort(A,left,mid)
		cnt_r = mergeSort(A,mid,right)

		return merge(A,left,mid,right)+cnt_l+cnt_r

	return 0

if __name__ == '__main__':

	num = int(input())
	A = [int(i) for i in input().split()]

	left = 0
	right = len(A)

	count = mergeSort(A,left,right)

	print(" ".join(map(str,A)))
	print(count)

