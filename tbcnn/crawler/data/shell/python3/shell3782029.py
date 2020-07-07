cnt = 0
m = 0
gap = []

def insertion_sort(nums, n, g):
    global cnt
    for i in range(1, n):
        key = nums[i]
        j = i - g
        while j >= 0 and nums[j] > key:
            nums[j + g] = nums[j]
            j -= g
            cnt += 1
        nums[j + g] = key

def shell_sort(nums, n):
    global m
    g = 0
    while True:
        g = g * 3 + 1
        if g > n:
            break
        gap.append(g)
    gap.reverse()
    m = len(gap)
    for i in range(m):
        insertion_sort(nums, n, gap[i])

n =  int(input())
nums = []
for i in range(n):
    nums.append(int(input()))
shell_sort(nums, n)

print(m)
print(' '.join(map(str, gap)))
print(cnt)
for i in range(n):
    print(nums[i])

