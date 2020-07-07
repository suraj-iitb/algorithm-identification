n=int(input())
cnt=0
a=list(map(int,input().split()))

def Merge(A, left, mid, right):
	n1 = mid - left
	n2 = right - mid
	L=[0]*(n1+1)
	R=[0]*(n2+1)
	for i in range(n1):
		L[i] = A[left + i]
	for i in range(n2):
		R[i] = A[mid + i]
	L[n1] = 10**10
	R[n2] = 10**10
	i = 0
	j = 0
	global cnt
	for k in range(left,right):
		cnt+=1
		if L[i] <= R[j]:
			A[k] = L[i]
			i+=1
		else:
			A[k] = R[j]
			j+=1

def MergeSort(A, left, right):
	if left+1 < right:
		mid = (left + right)//2
		MergeSort(A, left, mid)
		MergeSort(A, mid, right)
		Merge(A, left, mid, right)
MergeSort(a,0,n)
print(*a)
print(cnt)




