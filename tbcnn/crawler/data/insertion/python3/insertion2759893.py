n = int(input())
a_list = list(map(int, input().split()))

print(' '.join(map(str, a_list)))
for i in range(1, n):
    v = a_list[i]
    j = i-1
    while j >= 0 and a_list[j] > v:
        a_list[j+1] = a_list[j]
        j -= 1
    a_list[j+1] = v
    print(' '.join(map(str, a_list)))

