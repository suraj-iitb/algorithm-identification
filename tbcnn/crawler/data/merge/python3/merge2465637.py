def merge(S, left, mid, right):
	global cnt
	L = S[left:mid] + [float('inf')]
	R = S[mid:right] + [float('inf')]
	i,j = 0,0
	for k in range(left,right):
		if L[i] <= R[j]:
			S[k] = L[i]
			i += 1
		else:
			S[k] = R[j]
			j += 1
	cnt += right - left


def merge_sort(S, left = 0, right = 500000):
	right = min(len(S),right)
	if left+1 < right:
		mid = (left+right) // 2
		merge_sort(S, left, mid)
		merge_sort(S, mid, right)
		merge(S, left, mid, right)


if __name__ == '__main__':
	n = int(input())
	S = [int(s) for s in input().split()]
	cnt = 0
	merge_sort(S)
	print(*S)
	print(cnt)
