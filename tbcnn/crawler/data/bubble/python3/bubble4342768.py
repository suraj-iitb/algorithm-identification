N = int(input())
A = [int(x) for x in input().split()]
flag = True
swap = 0
while flag:
    flag = False
    for i in range(N-1,0,-1):
        if A[i-1] > A[i]:
            A[i-1], A[i] = A[i], A[i-1]
            swap += 1
            flag = True
            # break
print(" ".join(map(str,A)))
print(swap)
