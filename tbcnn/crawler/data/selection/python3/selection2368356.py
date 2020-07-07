n = int(input())
s = input().split(" ")
nums = list(map(int,s))
koukan = 0
for i in range(n):
    minj = i
    for j in range(i+1,n):
        if nums[j] < nums[minj]:
            minj = j
    w = nums[i]
    nums[i] = nums[minj]
    nums[minj] = w
    if i != minj:
        koukan += 1
for i in range(n):
    if i == n-1:
        print(nums[i])
    else:
        print(nums[i],end=" ")
print(koukan)
