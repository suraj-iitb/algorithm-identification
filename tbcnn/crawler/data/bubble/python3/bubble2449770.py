n = int(input())
k = [int(i) for i in input().split()]
M = 0
for i in range(n-1):
    for l in range(n-i-1):

        if k[n-2-l] > k[n-1-l]:
            v = k[n-1-l]
            k[n - 1 - l]=k[n-2-l]
            k[n - 2 - l]=v
            M+=1
        else:
            pass

print(' '.join(map(str, k)))
print(M)
