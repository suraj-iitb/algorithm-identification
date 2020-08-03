N = int(input())
A = [int(x) for x in input().split()]

count = 0

for i in range(N):
    minj = i
    for j in range(i,N):
        if A[j] < A[minj]:
            minj = j
    if not i == minj:
        A[i], A[minj] = A[minj], A[i]
        count += 1
        
print(" ".join(map(str, A)))
print(count)