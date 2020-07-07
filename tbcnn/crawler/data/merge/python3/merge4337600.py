n = int(input())
S = list(map(int, input().split()))
count = 0

def merge(A, left, mid, right):
	global count
	n1 = mid - left
	n2 = right - mid
	L = A[left:mid]
	R = A[mid:right]
	L.append(10000000000)
	R.append(10000000000)
	i = 0
	j = 0
	for k in range(left, right):
		count += 1
		if L[i] <= R[j]:
			A[k] = L[i]
			i += 1
		else:
			A[k] = R[j]
			j += 1

def mergeSort(A, left, right):
	if left + 1 < right:
		mid = (left + right) // 2
		mergeSort(A, left, mid)
		mergeSort(A, mid, right)
		merge(A, left, mid, right)

mergeSort(S, 0, n)
print(" ".join(map(str, S)))
print(count)
