num = int(input())

A = list(map(int, input().split()))
count = 0

flag = True
while flag:
        flag = False
        for j in range(num - 1, 0, -1):
                if A[j] < A[j - 1]:
                        A[j], A[j - 1] = A[j - 1], A[j]
                        count += 1
                        flag = True

tempA = map(str, A)
print(' '.join(tempA))
print(count)
