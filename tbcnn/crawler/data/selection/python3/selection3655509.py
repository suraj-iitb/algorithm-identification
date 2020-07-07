n = int(input())
a_list = list(map(int, input().split()))

swap_count = 0
for i in range(0, n):
    mini = i
    for j in range(i, n):
        if a_list[j] < a_list[mini]:
            mini = j
    if i != mini:
        temp = a_list[i]
        a_list[i] = a_list[mini]
        a_list[mini] = temp
        swap_count = swap_count + 1

print(' '.join(map(str, a_list)))
print(swap_count)
