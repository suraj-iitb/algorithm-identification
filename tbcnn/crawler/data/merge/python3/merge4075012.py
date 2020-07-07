def merge(A, left, mid, right):
	global count

	L = A[left:mid] + [1000000001]
	R = A[mid:right] + [1000000001]

	i = j = 0
	for k in range(left, right):
		if L[i] <= R[j]:
			A[k] = L[i]
			i += 1
		else:
			A[k] = R[j]
			j += 1
	count += right - left

def m_Sort(A, left, right):
	if left + 1 < right:
		mid = (left + right) // 2
		m_Sort(A, left, mid)
		m_Sort(A, mid, right)
		merge(A, left, mid, right)

if __name__ == '__main__':
	n = int(input())
	A = list(map(int, input().split()))
	count = 0
	m_Sort(A, 0, n)
	print(*A)
print(count)

