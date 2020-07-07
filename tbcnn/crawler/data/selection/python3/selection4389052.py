N = int(input())
A = [int(a) for a in input().split()]

cnt = 0
for i in range(N):
    mni = i
    for j in range(i + 1, N):
        if A[j] < A[mni]:
            mni = j
    if i != mni:
        A[i], A[mni] = A[mni], A[i]
        cnt += 1

print(*A)
print(cnt)
