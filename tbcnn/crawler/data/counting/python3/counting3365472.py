n = int(input())
A = [int(x) for x in input().split()]

B = [0] * n
C = [0] * 10001

for a in A:
    C[a] += 1

j = 0
for i in range(10001):
    for c in range(C[i]):
        B[j] = i
        j += 1

print(' '.join([str(x) for x in B]))

