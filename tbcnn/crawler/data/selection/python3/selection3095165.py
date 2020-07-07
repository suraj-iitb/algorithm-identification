N = int(input())
A = list(map(int,input().split()))

cnt = 0
for i in range(0, N):
    mini = i
    # search for the minimum element in A[i, i+1, ..., N-1]
    for j in range(i,N):
        if A[j] < A[mini]:
            mini = j
    # swap A[i] and A[mini]
    if i != mini:
        cnt += 1
        A[i], A[mini] = A[mini], A[i]
    
print( ' '.join(map(str, A) ) )
print(cnt)
