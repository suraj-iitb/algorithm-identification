import sys

def merge(A, left, mid, right, num_compare):
	n1 = mid - left
	n2 = right - mid

	L = A[left:mid] + [SENTINEL]
	R = A[mid:right] + [SENTINEL]
	
	i = 0
	j = 0

	num_compare += right - left
	for k in range(left, right):
		if L[i] <= R[j]:
			A[k] = L[i]
			i += 1
		else:
			A[k] = R[j]
			j += 1
	return num_compare

def merge_sort(A, left, right, num_compare):
	if left + 1 < right:
		mid = (left + right) // 2
		num_compare = merge_sort(A, left, mid, num_compare)
		num_compare = merge_sort(A, mid, right, num_compare)
		num_compare = merge(A, left, mid, right, num_compare)

	return num_compare


#fin = open("test.txt", "r")
fin = sys.stdin

SENTINEL = float("inf")

n = int(fin.readline())
S = list(map(int, fin.readline().split()))

num_compare = 0
num_compare = merge_sort(S, 0, n, num_compare)

print(S[0], end = "")
for s in S[1:]:
	print(" " + str(s), end = "")
print("") 
print(num_compare)
