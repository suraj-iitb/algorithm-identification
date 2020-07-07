def bubble_sort(nums, n):
    count = 0
    flag = True
    while flag:
        flag = False
        for i in reversed(range(1, n)):
            if nums[i] < nums[i-1]:
                tmp = nums[i]
                nums[i] = nums[i-1]
                nums[i-1] = tmp
                count += 1
                flag = True

    nums_str = map(str, nums)
    print(" ".join(nums_str))
    print(count)

if __name__=="__main__":
    n = int(input())
    nums = list(map(int, input().split()))
    bubble_sort(nums, n)

