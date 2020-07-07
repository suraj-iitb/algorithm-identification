N = int(input())
A = list(map(int, input().split()))

count = 0
flag = 1
i = 0
while flag:
    flag = 0
    for j in range(N-1, i, -1):
        if A[j] < A[j-1]:
            A[j], A[j-1] = A[j-1], A[j] #交換
            flag = 1
            count += 1
    i += 1
        
for k in range(N):
        if k > 0:
            print(' ', end='')
        print(A[k], end='')

print('')
print(count)
