def bubble_sort(A):
    cnt = 0
    for i in range(len(A) - 1):
        for j in reversed(range(i+1, len(A))):
            if A[j] < A[j - 1]:
                cnt += 1
                tmp = A[j]
                A[j] = A[j - 1]
                A[j - 1] = tmp
    return cnt

cnt = 0
amount = int(input())
nl = list(map(int, input().split()))

cnt = bubble_sort(nl)

for i in range(amount - 1):
    print(nl[i], end=" ")
print(nl[amount - 1])
print(cnt)
