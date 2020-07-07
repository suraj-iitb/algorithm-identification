num = int(input())
A = list(map(int, input().split()))
count = 0
for i in range(num-1):
    min_j = i
    for j in range(i+1, num):
        if A[min_j] > A[j]:
            min_j = j
    if min_j != i:
        a = A[i]
        A[i] = A[min_j]
        A[min_j] = a
        count += 1
A_str = [str(k) for k in A]
print(' '.join(A_str))
print(count)
