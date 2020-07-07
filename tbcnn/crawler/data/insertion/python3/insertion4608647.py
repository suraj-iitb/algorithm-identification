N = int(input())
line = list(map(int, input().split()))
print(' '.join(map(str, line)))
for i in range(1, N):
    tmp = line[i]
    j = i - 1
    while j >= 0 and line[j] > tmp:
        line[j + 1] = line[j]
        j -= 1
    line[j + 1] = tmp
    print(' '.join(map(str, line)))
