N = int(input())
A = list(map(int, input().split()))
counter = 0
for i in range(0, N):
    minj = i
    for j in range(i, N):
        if A[j]<A[minj]:
            minj = j
    if i!=minj:
        counter += 1
        A[i], A[minj] = A[minj], A[i]   
print(' '.join(map(str, A)))
print(counter)
