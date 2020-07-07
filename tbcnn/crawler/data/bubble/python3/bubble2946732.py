N = int(input())
arr = [int(n) for n in input().split()]

swap_cnt = 0
swap_flg = True
i = 0
while swap_flg:
    swap_flg = False
    for j in range(N - 1, i, -1):
        if (arr[j] < arr[j - 1]):
            arr[j], arr[j - 1] = arr[j - 1], arr[j]
            swap_cnt += 1
            swap_flg = True
    i += 1

print(' '.join(map(str, arr)))
print(swap_cnt)
