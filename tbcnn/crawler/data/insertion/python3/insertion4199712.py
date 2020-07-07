N = int(input())
nums = input()
print(nums)
A = list(map(int, nums.split()))

for i in range(1,N):
    v = A[i]
    j = i-1
    while j >= 0 and A[j] > v:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = v
    print(" ".join(map(str, A)))
