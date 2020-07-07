def counting_sort(A, k):
    B, C = [], [0]*(k+1)
    for j in range(0, len(A)):
        C[A[j]] += 1
    for i in range(0, len(C)):
        while True:
            if C[i] != 0:
                B.append(i)
                C[i] -= 1
            else:
                break
    return B

input()
num = list(map(int, input().split()))
result = counting_sort(num, max(num))
print(*result)
