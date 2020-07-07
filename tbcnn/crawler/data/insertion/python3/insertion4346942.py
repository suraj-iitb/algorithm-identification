def print_list(l):
    print(' '.join(map(str, l)))


n = int(input())
l = list(map(int, input().split()))

print_list(l)

for i in range(1, n):
    v = l[i]
    j = i - 1
    while j >= 0 and l[j] > v:
        l[j + 1] = l[j]
        j -= 1
    l[j + 1] = v
    print_list(l)

