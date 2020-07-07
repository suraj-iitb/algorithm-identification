num = int(input())

A = list(map(int, input().split()))
tempA = map(str, A)
print(' '.join(tempA))

for i in range(1, num):
        temp = A[i]
        j = i - 1
        while j >= 0 and A[j] > temp:
                A[j + 1] = A[j]
                j -= 1
        A[j + 1] = temp
        tempA = map(str, A)
        print(' '.join(tempA))
