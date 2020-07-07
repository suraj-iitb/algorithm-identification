# selection sort
N = int(input())
A = [int(i) for i in input().split()]

cnt = 0

for i in range(0, N):
    min_i = i
    for j in range(i+1, N):
        if A[j] < A[min_i]:
            min_i = j
    if i != min_i:
        A[i], A[min_i] = A[min_i], A[i]
        cnt = cnt + 1

print(' '.join([str(i) for i in A]))
print(cnt)
