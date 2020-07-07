N = int(input())
line = list(map(int, input().split()))

cnt = 0
for i in range(N):
    minj = i
    for j in range(i+1, N):
        if line[j] < line[minj]:
            minj = j
    if minj != i:
        tmp = line[i]
        line[i] = line[minj]
        line[minj] = tmp
        cnt += 1

print(' '.join(list(map(str, line))))
print(cnt)
