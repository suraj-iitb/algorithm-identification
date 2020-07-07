time = int(input())
nums = list(map(int,input().split(" ")))
count = 0

for i in range(time):
    top = nums[i]
    mi = min(nums[i:])
    if top > mi:
        count += 1
        a = top
        #0が複数あるからここでひっかかってしまう
        #同じ値がある場合にどうやって最小値の位置を特定するのかが問題
        tmpIndex = nums[i:].index(mi) + i
        nums[i] = mi
        nums[tmpIndex] = a

print(' '.join(map(str,nums)))
print(count)

