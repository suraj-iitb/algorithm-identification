N = int(input())
A = list(map(int, input().split()))
count = 0

for i in range(0, N):
    min_A = A[i]
    for j in range(i, N):
        if A[j] < min_A:
            min_A = A[j]
            num = j
    if min_A < A[i]:
        v = A[i]
        A[i] = min_A
        A[num] = v
        count += 1

s = [str(a) for a in A]
s = " ".join(s)
print(s)
print(count)

