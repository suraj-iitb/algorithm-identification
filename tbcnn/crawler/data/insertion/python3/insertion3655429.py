n = int(input())
a_list = list(map(int, input().split()))

print(' '.join(map(str, a_list)))
for i in range(1, n):
    key = a_list[i]
    j = i - 1
    while j >= 0 and a_list[j] > key:
        a_list[j + 1] = a_list[j]
        j = j - 1
    a_list[j + 1] = key
    print(' '.join(map(str, a_list)))
