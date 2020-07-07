def main() :
    n = int(input())
    nums = [int(i) for i in input().split()]

    flag = True
    count = 0
    index = 0
    while flag :
        flag = False
        for i in reversed(range(index+1, n)) :
            if nums[i-1] > nums[i] :
                nums[i-1], nums[i] = nums[i], nums[i-1]
                count += 1
                flag = True
        index += 1

    nums_str = [str(i) for i in nums]
    print(" ".join(nums_str))
    print(count)

if __name__ == '__main__' :
    main()
