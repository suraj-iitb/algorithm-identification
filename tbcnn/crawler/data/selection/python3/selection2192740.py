N = int(input())

A = [int(x) for x in input().split()]
num_c = 0
for i in range(0, N):
    minj = i
    for j in range(i, N):
        if A[j] < A[minj]:
            minj = j
    if(i != minj):
        A[i], A[minj] = A[minj], A[i]
        num_c += 1

print((" ").join(str(x) for x in A))
print(num_c)
