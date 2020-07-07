n = int(input())
l = list(map(int, input().split()))

count = 0

for i in range(n):
    min_index = i
    for j in range(i, n):
        if l[min_index] > l[j]:
            min_index = j
    if min_index != i:
        l[i], l[min_index] = l[min_index], l[i]
        count += 1

print(' '.join(map(str, l)))
print(count)

