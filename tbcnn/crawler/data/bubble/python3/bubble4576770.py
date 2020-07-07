N = int(input())
A = list(map(int, input().split()))

nums = []
for i in range(1, N):
    nums.append(i)
    
nums.sort(reverse=True)

flag = 1
cnt = 0
while flag:
    flag = 0
    for num in nums:
        if A[num] < A[num-1]:
            A[num-1], A[num] = A[num], A[num-1]
            flag = 1
            cnt += 1

print(' '.join(map(str, A)))
print(cnt)
