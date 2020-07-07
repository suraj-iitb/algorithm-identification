#selection sort
N = int(input())
nums = list(map(int,input().split()))

count = 0 #交換回数
for i in range(N):
    minj = i
    for j in range(i+1,N): #配列を探索し、最小値を見つける
        if nums[minj] > nums[j]:
            minj = j
    if i != minj:
        temp = nums[i] #iの値を一時保管
        nums[i] = nums[minj] #iの位置に最小値を入れて交換する
        nums[minj] = temp
        count = count + 1

print(' '.join(map(str,nums)))
print(count)
