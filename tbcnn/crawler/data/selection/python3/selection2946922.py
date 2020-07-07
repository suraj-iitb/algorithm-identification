N = int(input())
arr = [int(n) for n in input().split()]

swap_cnt = 0
for i in range(0, N):
    minj = i
    for j in range(i, N):
        if arr[j] < arr[minj]:
            minj = j
    if (i != minj):
        arr[i], arr[minj] = arr[minj], arr[i]
        swap_cnt += 1

print(' '.join(map(str, arr)))
print(swap_cnt)

