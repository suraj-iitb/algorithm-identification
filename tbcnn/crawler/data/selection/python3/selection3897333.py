def selection_sort(nums, n):
    count = 0
    for i in range(n):
        minj = i
        flag = False
        for j in range(i, n-1):
            if nums[minj] > nums[j+1]:
                minj = j+1
                flag = True
        
        if flag:
            tmp = nums[i]
            nums[i] = nums[minj]
            nums[minj] = tmp
            count += 1


    nums_str = map(str, nums)
    print(" ".join(nums_str))
    print(count)

if __name__=="__main__":
    n = int(input())
    nums = list(map(int, input().split()))
    selection_sort(nums, n)

