# https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_B

n = int(input())
A = list(map(int, input().split()))
	
# マージソート
def merge_sort(arr, left, right):
	# merge_sort(lst, 0, len(lst))
	global cnt
	if right - left == 1:
		return 
	mid = left + (right - left) // 2
	merge_sort(arr, left, mid)
	merge_sort(arr, mid, right)
	a = [arr[i] for i in range(left, mid)] \
		+ [arr[i] for i in range(right - 1, mid - 1, -1)]
	iterator_left = 0
	iterator_right = len(a) - 1
	for i in range(left, right):
		cnt += 1
		if a[iterator_left] <= a[iterator_right]:
			arr[i] = a[iterator_left]
			iterator_left += 1
		else:
			arr[i] = a[iterator_right]
			iterator_right -= 1

cnt = 0
merge_sort(A, 0, n)
print(*A)
print(cnt)
