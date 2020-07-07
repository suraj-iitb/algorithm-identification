def insertion_sort(a_list, n, g):
    cnt = 0
    for i in range(g, n):
        v = a_list[i]
        j = i - g
        while j >= 0 and a_list[j] > v:
            a_list[j + g] = a_list[j]
            j = j - g
            cnt = cnt + 1
        a_list[j + g] = v
    return cnt


n = int(input())
a_list = []
for i in range(0, n):
    a_list.append(int(input()))

cnt = 0
g_list = [1]
g = 1
while g < n:
    g_list.append(g)
    g = 3 * g + 1
g_list = list(reversed(g_list))
m = len(g_list)
cnt = 0
for i in range(0, m):
    cnt = cnt + insertion_sort(a_list, n, g_list[i])

print(m)
print(' '.join(map(str, g_list)))
print(cnt)
for a in a_list:
    print(a)
