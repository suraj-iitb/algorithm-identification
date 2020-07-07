n = int(input())
#A = [int(input()) for i in range(n)]
L = [int(i) for i in input().split()]

def InsertionSort(A,N):
	for i in range(1,N):
		key = A[i]
		j = i - 1
		while j>=0 and A[j] > key:
			A[j+1] = A[j]
			j -= 1
		A[j+1]  = key

		for item in range(len(A)):
			if item == len(A)-1:
				print(A[item])
			else:
				print(A[item],end=" ")

for item in range(len(L)):
	if item == len(L)-1:
		print(L[item])
	else:
		print(L[item],end=" ")

InsertionSort(L,n)






"""
for i in range(len(A)):
	if i == len(A)-1:
		print(A[i])
	else:
		print(A[i],end=" ")
"""

