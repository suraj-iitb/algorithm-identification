n = int(input())
A = list(map(int, input().split()))
count = 0

for i in range(n):
    minj = i
    for j in range(i, n):
        if A[j] < A[minj]:
            minj = j
        else:
            pass
    A[i], A[minj] = A[minj], A[i]
    if i != minj:
        count += 1
        
print(*A)
print(count)
