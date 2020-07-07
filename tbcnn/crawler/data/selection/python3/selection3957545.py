# selectionSort(A, N) // N個の要素を含む0-オリジンの配列A
#   for i が 0 から N-1 まで
#     minj = i
#    for j が i から N-1 まで
#       if A[j] < A[minj]
#         minj = j
#     A[i] と A[minj] を交換

n = int(input())
nums = list(map(int, input().split()))
count = 0
for i in range(0, n-1):
    minj = i
    for j in range(i, n):
        if nums[j] < nums[minj]:
            minj = j
            
    nums[i], nums[minj] = nums[minj], nums[i]
    if i != minj:
        count += 1
    
        


print(*nums)
print(count)
