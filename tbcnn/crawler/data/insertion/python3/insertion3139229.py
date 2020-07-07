# -*- coding: utf-8 -*-
n = int(input())
nums = list(map(int, input().split()))

for i in range(1, n):
    print(" ".join(map(str, nums)))
    v = nums[i]
    j = i - 1
    while j >= 0 and nums[j] > v:
        nums[j + 1] = nums[j]
        j -= 1
    nums[j + 1] = v

print(" ".join(map(str, nums)))

