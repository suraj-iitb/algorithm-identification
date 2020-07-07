def insertionSort(At, Nt):
	for i in range(Nt):
		v = At[i]
		j = i - 1
		while j >= 0 and At[j] > v:
			A[j + 1] = A[j]
			j = j - 1
		A[j + 1] = v
		print(" ".join(map(str,At)))
	return At

if __name__ == '__main__':
	N = int(input())
	A = list(map(int, input().split()))
	A = insertionSort(A, N)
	#print(" ".join(map(str,A)))
