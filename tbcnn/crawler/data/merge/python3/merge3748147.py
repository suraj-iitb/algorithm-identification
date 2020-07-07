def merge(A,left,mid,right):
	L=A[left:mid]+[10**9]
	R=A[mid:right]+[10**9]
	i = 0
	j = 0
	c = 0
	for k in range(left,right):
		c += 1
		if L[i] <= R[j]:
			A[k] = L[i]
			i+=1
		else:
			A[k] = R[j]
			j+=1
	return c

def merge_sort(A,left,right):
	if left+1 < right:
		mid = (left+right) // 2
		cL=merge_sort(A,left,mid)
		cR=merge_sort(A,mid,right)
		return(merge(A,left,mid,right) + cL + cR)
	return 0

c=0
n = int(input())
A = [int(i) for i in input().split()]
c=merge_sort(A,0,n)
print(*A)
print(c)
