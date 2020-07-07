n = int(input())
a = list(map(int, input().split()))

flag = True
swap_count = 0
for i in range(0, n):
    if not flag:
        break
    flag = False
    for j in range(n-1, 0, -1):
        if a[j] < a[j-1]:
            a[j], a[j-1] = a[j-1], a[j]
            flag = True
            swap_count += 1

print(' '.join(map(str, a)))
print(swap_count)

