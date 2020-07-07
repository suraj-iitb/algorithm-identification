1# bubbleSort(A, N) // N 個の要素を含む 0-オリジンの配列 A
2#   flag = 1 // 逆の隣接要素が存在する
3#   while flag
4#     flag = 0
5#     for j が N-1 から 1 まで
6#       if A[j] < A[j-1]
7#         A[j] と A[j-1] を交換
8#         flag = 1

n = int(input())
nums = list(map(int, input().split()))
count = 0
flag = True
while flag:
    flag = False
    for j in range(n-1, 0, -1):
        if nums[j] < nums[j-1]:
            nums[j], nums[j-1] = nums[j-1], nums[j]
            count += 1
            flag = True

print(*nums)
print(count)
