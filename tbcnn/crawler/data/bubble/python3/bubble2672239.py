def bubble_sort_aoj(nums, len):
    '''バブルソート：隣接項の比較'''
    flag = True
    count = 0
    
    while flag:
        flag = False
        
        for i in range(len - 1, 0, -1):
            if nums[i] < nums[i-1]:
                nums[i], nums[i-1] = nums[i-1], nums[i]
                flag = True
                count += 1
    
    return nums, count

if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split(' ')))

    ans = bubble_sort_aoj(A, N)

    print(' '.join([str(x) for x in ans[0]]))
    print(ans[1])
