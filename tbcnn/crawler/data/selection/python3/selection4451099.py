N = int(input())
A = list(map(int, input().split()))

cnt = 0
for i in range(N):
    mini = i
    for j in range(i,N):
        if A[j] < A[mini]:
            mini = j
    if mini != i:
        tmp = A[i]
        A[i] = A[mini]
        A[mini] = tmp
        cnt += 1

result = [str(i) for i in A]
print(' '.join(result))
print(cnt)

