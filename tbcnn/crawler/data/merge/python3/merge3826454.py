def merge(A,left,mid,right):
	global count
	
	n1=mid-left
	n2=right-mid
	L=A[left:mid]
	R=A[mid:right]
	# for i in range(n1):
	# 	L[i]=A[left+i]
	# for i in range(n2):
	# 	R[i]=A[mid+i]
	L.append(float('inf'))
	R.append(float('inf'))
	i,j=0,0
	# print(L,R)
	for k in range(left,right):
		count+=1
		if L[i]<=R[j]:
			A[k]=L[i]
			i=i+1
		else:
			A[k]=R[j]
			j=j+1

def mergesort(A,left,right):
	if left+1<right:
		mid=(left+right)//2
		mergesort(A,left,mid)
		mergesort(A,mid,right)
		merge(A,left,mid,right)

n=int(input())
A=list(map(int,input().split()))
count=0
mergesort(A,0,n)
print(*A)
print(count)
