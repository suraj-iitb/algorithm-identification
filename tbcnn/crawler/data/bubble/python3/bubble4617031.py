def main():
    num = int(input())
    nums = list(map(int, input().split()))
    
    flag = True
    i = 0
    swap_num = 0
    while flag:
        flag = False
        for j in range(num-1, i, -1):
            if nums[j] < nums[j - 1]:
                temp = nums[j-1]
                nums[j-1] = nums[j]
                nums[j] = temp
                flag = True
                swap_num += 1
                
        i += 1
    print(" ".join([str(n) for n in nums]))
    print(swap_num)
                

if __name__ == '__main__':
    main()
    
