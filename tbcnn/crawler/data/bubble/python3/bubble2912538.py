def print_list():
    for i,e in enumerate(A):
        if i == N - 1:
            print(e)
        else:
            print(e, end=" ")

N = int(input())
A = [int(e) for e in input().split()]
flag = 1; cnt = 0
while flag == 1:
    flag = 0
    for i in range(N-1, 0, -1):
        if A[i] < A[i-1]:
            w = A[i]; A[i] = A[i-1]; A[i-1] = w
            cnt += 1
            flag = 1
print_list()
print(cnt)

