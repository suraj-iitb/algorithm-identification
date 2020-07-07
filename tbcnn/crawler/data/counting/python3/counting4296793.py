N = int(input())
A = list(map(int, input().split()))

M = [0]*10001
for a in A:
    M[a] += 1

first = True
for i, m in enumerate(M):
    if m > 0:
        if first:
            print(*([i]*m), end='')
            first = False
        else:
            print(' ', end='')
            print(*([i]*m), end='')
print()

