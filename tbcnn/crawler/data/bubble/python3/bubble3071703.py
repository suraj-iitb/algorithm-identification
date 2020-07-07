def bubble_sort(nums, n):
    c = 0

    loop = True
    while loop:
        loop = False

        for j in range(n-1, 0, -1):
            if nums[j] < nums[j-1]:
                nums[j], nums[j-1] = nums[j-1], nums[j]
                loop = True
                c += 1

    return (c, nums)

def main():
    n = int(input())
    nums = [int(x) for x in input().split()]

    c, nums = bubble_sort(nums, n)

    print(" ".join([str(x) for x in nums]))
    print(c)

if __name__ == '__main__':
    main()

