def insertionSort(A):
	for i in range(1, len(A)):
		j = A[i]
		k = i
		while k - 1 >= 0:
			if A[k - 1] > j:
				A[k] = A[k - 1]
				A[k - 1] = j
			k = k - 1
	return A


def insertionSort(m, A, CNT):
	for i in range(m, len(A)):
		j = A[i]
		k = i
		while k - m >= 0 and A[k-m] > j:
			A[k] = A[k - m]
			A[k - m] = j
			CNT = CNT + 1
			k = k - m
#	while k - m >= 0:
#		if A[k - m] > j:
#			A[k] = A[k - m]
#			A[k - m] = j
#			CNT = CNT + 1
#		k = k - m
	return A, CNT


n = int(input())  # 例:6
a = []  # 例:[1, 4, 3, 6, 2, 5]
for i in range(0, n):
	a.append(int(input()))
cnt = 0

M = []
temp = 1
while temp <= n:
	M.append(temp)
	temp = 3 * temp + 1
M.sort(reverse=True)
#M=[1]
for j in M:
	a, cnt = insertionSort(j, a, cnt)

print(len(M))
print(' '.join([str(n) for n in M]))
print(cnt)
for k in a:
	print(k)

