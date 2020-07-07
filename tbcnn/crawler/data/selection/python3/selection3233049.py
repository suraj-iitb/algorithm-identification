def selection_sort(n, nums):
    cnt = 0
    for i in range(n):
        minj = i
        for j in range(i, n):
            if nums[j] <  nums[minj]:
                minj=j
        if i != minj:              
            tmp = nums[i]
            nums[i] = nums[minj]
            nums[minj] = tmp
            cnt += 1
            
    print(' '.join(map(str, nums)))
    print(cnt)

def main():
    n = int(input())
    line = input()
    nums = list(map(int, line.split()))

    selection_sort(n, nums)

if __name__ == "__main__":
    main()
