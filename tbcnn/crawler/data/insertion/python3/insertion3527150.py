num = int(input())
A = list(map(int,input().split(" ")))

for i in range(num):
	v = A[i]
	j = i -1

	while j >= 0 and A[j] > v:
		A[j+1] = A[j]
		j -= 1
	A[j+1] = v

	#出力用
	list2 = [str(k) for k in A]
	print(" ".join(list2))

