num = int(input())

A = list(map(int, input().split()))
count = 0

for i in range(0, num):
        minID = i
        for j in range(i, num):
                if A[j] < A[minID]:
                        minID = j
        if i != minID:
                A[i],  A[minID] = A[minID], A[i]
                count += 1

tempA = map(str, A)
print(' '.join(tempA))
print(count)
