n = int(input())
A = list(map(int, input().split()))
count = 0

for i in range(n-1):
    frag = 0
    minj = i
    for j in range(i+1,n):
        if A[minj] > A[j]:
            minj = j
            frag = 1

    if frag:
        v = A[minj]
        A[minj] = A[i]
        A[i] = v
        count += 1

print(' '.join(map(str, A)))
print(str(count))
