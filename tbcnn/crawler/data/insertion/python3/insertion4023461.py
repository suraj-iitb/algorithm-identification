def insertSort(li,num):
	for i in range(1,num):
		j = i
		while li[j] < li[j-1] and j > 0 :
			tmp = li[j]
			li[j] = li[j-1]
			li[j-1] = tmp
			j -=1

		for k in range(len(li)):
			if k != len(li)-1:
				print(li[k],"",end="")
			else:
				print(li[k])

if __name__ == '__main__':
	num = int(input())
	li = list(map(int,input().split()))

	for i in range(len(li)):
		if i != len(li)-1:
			print(li[i],"",end="")
		else:
			print(li[i])

	insertSort(li,num)
