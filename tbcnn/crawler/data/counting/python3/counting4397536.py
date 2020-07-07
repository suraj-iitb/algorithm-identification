n = int(input())
A = list(map(int, input().split()))

def counting_sort(arr):
	max_num = max(arr)
	min_num = min(arr)
	count = [0] * (max_num - min_num + 1)
	for ele in arr:
		count[ele - min_num] += 1
	return [ele for ele, cnt in enumerate(count, start=min_num) for _ in range(cnt)]


AA = counting_sort(A)
print(*AA)
