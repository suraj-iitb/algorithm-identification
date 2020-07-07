def selection_sort(nums, n):
    c = 0

    for i in range(n):
        minj = i

        for j in range(i, n):
            if nums[j] < nums[minj]:
                minj = j

        if i != minj:
            nums[i], nums[minj] = nums[minj], nums[i]
            c += 1

    return (c, nums)

def main():
    n = int(input())
    nums = [int(x) for x in input().split()]

    c, nums = selection_sort(nums, n)

    print(" ".join([str(x) for x in nums]))
    print(c)

if __name__ == '__main__':
    main()

