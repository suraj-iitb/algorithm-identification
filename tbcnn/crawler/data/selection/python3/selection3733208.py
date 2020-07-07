def show(A):
    L = list(map(str, A))
    print(" ".join(L))

N = int(input())
A = list(map(int, input().split()))
cnt = 0

for i in range(0, N):
    minj = i
    for j in range(i, N):
        if A[j] < A[minj]:
            minj = j
    if A[i] != A[minj]:
        cnt += 1
        A[i], A[minj] = A[minj], A[i]
    
show(A)
print(cnt)
