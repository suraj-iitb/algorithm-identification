n = int(input())
a = list(map(int, input().split()))

swap_count = 0
for i in range(n):
    flag = False
    minj = i
    for j in range(i, n):
        if a[j] < a[minj]:
            minj = j
            flag = True
    if flag:
        a[i], a[minj] = a[minj], a[i]
        swap_count += 1

print(' '.join(map(str, a)))
print(swap_count)

