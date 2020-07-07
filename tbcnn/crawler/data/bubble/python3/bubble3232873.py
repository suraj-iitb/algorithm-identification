def bubble_sort(n, nums):
    flag = 1
    cnt = 0
    while flag:
        flag = 0
        for i in range(n-1, 0, -1):
            if nums[i] < nums[i-1]:
                tmp = nums[i]
                nums[i] = nums[i-1]
                nums[i-1] = tmp
                flag = 1
                cnt += 1
    print(' '.join(map(str, nums)))
    print(cnt)

def main():
    n = int(input())
    line = input()
    nums = list(map(int, line.split()))

    bubble_sort(n, nums)

if __name__ == "__main__":
    main()
