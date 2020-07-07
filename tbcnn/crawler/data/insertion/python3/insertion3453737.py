def show(nums):
    print(" ".join(list(map(str, nums))))


def insertion_sort(nums):
    show(nums)
    for i in range(1, len(nums)):
        v = nums[i]
        j = i - 1
        while j >= 0 and nums[j] > v:
            nums[j + 1] = nums[j]
            j -= 1
        nums[j + 1] = v
        show(nums)


N = int(input())
A = list(map(int, input().split()))
insertion_sort(A)

