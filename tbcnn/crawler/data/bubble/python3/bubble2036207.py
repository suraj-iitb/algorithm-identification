N = int(input())
A = [int(i) for i in input().split()]

counter = 0
flag = 1  #????????£??\????´?????????¨??????
while flag:
    flag = 0
    for j in range(N-1, 0, -1):
        if A[j] < A[j-1]:
            v = A[j]
            A[j] = A[j-1]
            A[j-1] = v
            flag = 1
            counter += 1

print(' '.join([str(A[i]) for i in range(0, N)]))
print(counter)
