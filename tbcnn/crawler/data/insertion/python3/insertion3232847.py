def insertion_sort(n, nums):
    print(' '.join(map(str,nums)))
    for i in range(1, n):
        v = nums[i]
        j = i -1
        while j>=0 and v < nums[j]:
            nums[j+1] = nums[j]
            j-=1
        nums[j+1] = v
        print(' '.join(map(str,nums)))


def main():
    n = int(input())
    line = input()
    nums = list(map(int, line.split()))

    insertion_sort(n, nums)

if __name__ == "__main__":
    main()
