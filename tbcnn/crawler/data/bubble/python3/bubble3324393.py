from sys import stdin

N = int(stdin.readline().rstrip())
A = [int(x) for x in stdin.readline().rstrip().split()]

count = 0
flg = True
while flg:
    flg = False
    for j in range(N-1, 0, -1):
        if A[j] < A[j-1]:
            A[j], A[j-1] = A[j-1], A[j]
            count += 1
            flg = True

print(*A)
print(count)
