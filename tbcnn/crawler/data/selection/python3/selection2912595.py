def print_list():
    for i,e in enumerate(A):
        if i == N - 1:
            print(e)
        else:
            print(e, end=" ")

N = int(input())
A = [int(e) for e in input().split()]
cnt = 0
for i in range(N):
    min_index = i
    for j in range(i, N):
        if A[min_index] > A[j]:
            min_index = j
    if i != min_index:
        w = A[i]; A[i] = A[min_index]; A[min_index] = w
        cnt += 1
print_list()
print(cnt)

