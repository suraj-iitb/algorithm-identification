#Counting Sort

def CountingSort(A, B, k):
    C = [0] * (k + 1)

    #C[i]に出現数を記録する
    for i in range(len(A)):
        C[A[i]] += 1

    for i in range(1, k+1):
        C[i] = C[i] + C[i-1]

    for i in reversed(range(len(A))):
        B[C[A[i]]-1] = A[i]
        C[A[i]] -= 1

    return B

n = int(input())
A = list(map(int, input().split()))
B = [0] * len(A)
k = 10000

B = CountingSort(A, B, k)

result = ''

for b in B:
    result += str(b) + ' '

print(result[:-1])
