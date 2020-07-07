n = int(input())
s = input().split(" ")
nums = list(map(int,s))
flag = 1
koukan = 0
while flag:
    flag = 0
    for i in range(n-1, 0, -1):
        if nums[i] < nums[i-1]:
            w = nums[i]
            nums[i] = nums[i-1]
            nums[i-1] = w
            koukan += 1
            flag = 1
for i in range(n):
    if i == n-1:
        print(nums[i])
    else:
        print(nums[i],end=" ")
print(koukan)
