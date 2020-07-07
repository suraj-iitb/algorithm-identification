n = int(input())
a_list = list(map(int, input().split()))

swap_count = 0
for i in range(0, n):
    for j in reversed(range(i + 1, n)):
        if a_list[j - 1] > a_list[j]:
            temp = a_list[j]
            a_list[j] = a_list[j - 1]
            a_list[j - 1] = temp
            swap_count = swap_count + 1

print(' '.join(map(str, a_list)))
print(swap_count)
