def main():
	length = int(input())
	target = list(map(int,input().split()))
	bubbleSort(target)

def bubbleSort(target):
	flag = True
	count = 0
	while flag:
		flag = False
		for i in range(len(target)-1,0,-1):
			if target[i] < target[i-1]:
				tmp = target[i]
				target[i] = target[i-1]
				target[i-1] = tmp
				flag = True
				count += 1


	print(*target,sep=' ')
	print(count)


if __name__ == '__main__':
	main()
