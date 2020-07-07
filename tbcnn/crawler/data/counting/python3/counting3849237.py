import sys

def CountingSort(A,B,k,n):

	C = [0] * k

	for i in range(n):
		C[A[i]] += 1

	for i in range(1,k):
		C[i] = C[i] + C[i-1]

	for i in range(n-1,-1,-1):
		B[C[A[i]]-1] = A[i]
		C[A[i]] -= 1


def test():

	n = int(sys.stdin.readline())
	A = list(map(int,sys.stdin.readline().split()))

	B = [0] * n

	max = 0
	for i in range(n):
		if max < A[i]:
			max = A[i]

	CountingSort(A,B,max+1,n)
	
	for i in range(n-1):
		print(f"{B[i]} ",end='')
	print(B[n-1])


if __name__ == "__main__":
	test()

