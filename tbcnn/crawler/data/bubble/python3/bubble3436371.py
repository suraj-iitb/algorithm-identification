time = int(input())

tmp = input().split(" ")
nums = []
for i in tmp:
    nums.append(int(i))

flag = 1
count = 0
while flag:
    flag = 0
    for i in range(time-1,0,-1):
        #ここにはいってない
        if nums[i] < nums[i-1]:
            count += 1
            a = nums[i-1]
            nums[i-1] = nums[i]
            nums[i] = a
            flag = 1

print(' '.join(map(str,nums)))
print(count)

