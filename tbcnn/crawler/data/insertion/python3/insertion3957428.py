#for i = 1 to A.length-1
#    key = A[i]
#    /* insert A[i] into the sorted sequence A[0,...,j-1] */
#j = i - 1
#   while j >= 0 and A[j] > key
#        A[j+1] = A[j]
#        j--
#    A[j+1] = key

n = int(input())
nums = list(map(int, input().split()))
for i in range(0, n):
    key = nums[i]
    j = i - 1
    while (j>=0) and (nums[j] > key):
        nums[j+1] = nums[j]
        j -= 1
    nums[j+1] = key
    print(*nums)
