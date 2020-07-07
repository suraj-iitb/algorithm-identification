n = int(input())
nums = [int(i) for i in input().split(" ")]

count = 0

def merge(nums, left, mid, right):
    i = 0
    j = 0
    nums_l = nums[left:mid]
    nums_r = nums[mid:right]
    nums_l.append(10 ** 9 + 1)
    nums_r.append(10 ** 9 + 1)
    for x in range(0, right - left):
        global count
        count = count + 1
        if nums_l[i] <= nums_r[j]:
            nums[left + x] = nums_l[i]
            i = i + 1
        else:
            nums[left + x] = nums_r[j]
            j = j + 1

def merge_sort(nums, left, right):
    if left + 1 < right:
        mid = int((left + right) / 2)
        merge_sort(nums, left, mid)
        merge_sort(nums, mid, right)
        merge(nums, left, mid, right)

merge_sort(nums, 0, n)
result = ""
for i in nums:
    result += str(i) + " "
print(result.rstrip())
print(count)
