N = int(input())
A = list(map(int, input().split()))
cnt = 0
for i in range (0, N-1):
    min = i
    for j in range(i+1, N):
        if A[j] < A[min]:
            min = j
    if min == i:
        continue
    else:
        tmp = A[min]
        A[min] = A[i]
        A[i] = tmp
        cnt += 1

print(" ".join(map(str, A)))
print(cnt)
