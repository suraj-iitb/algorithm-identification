def insert_sort(nums, n):
    for i in range(1, n):
        nums_str = map(str, nums)
        print(" ".join(nums_str))
        v = nums[i]
        j = i - 1
        while j >= 0 and nums[j] > v:
            nums[j+1] = nums[j]
            j-=1

        nums[j+1] = v

    nums_str = map(str, nums)
    print(" ".join(nums_str))


if __name__=="__main__":
    n = int(input())
    nums = list(map(int, input().split()))
    insert_sort(nums, n)
