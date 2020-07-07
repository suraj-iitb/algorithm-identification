#bubble sort
N = int(input())
nums = list(map(int,input().split()))

count = 0 #交換回数
for i in range(N): #先頭が確定するまで調べる（確定したら先頭の次の値が先頭になる）
    j = N-1
    while j > i:
        if nums[j-1] > nums[j]:
            temp = nums[j-1]
            nums[j-1] = nums[j]
            nums[j] = temp
            count = count + 1 #交換したらカウントする
        j = j - 1 #交換したら次の値に移動する

print(' '.join(map(str,nums)))
print(count)
