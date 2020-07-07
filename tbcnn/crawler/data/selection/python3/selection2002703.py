import sys

def selection_sort(nums, n):
    cnt = 0
    
    for i in range(n):
        minj = i
        for j in range(i, n):
            if nums[j] < nums[minj]:
                minj = j

        nums[i], nums[minj] = nums[minj], nums[i]
        if i != minj:
            cnt += 1

    print(' '.join([str(i) for i in nums]))
    print(cnt)
    
def main():
    n = int(sys.stdin.readline().strip())
    data = sys.stdin.readline().strip().split(' ')
    nums = [int(i) for i in data]
    selection_sort(nums, n)

if __name__ == '__main__':
    main()
    
