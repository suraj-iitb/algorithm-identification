n = int(input())
a_list = list(map(int, input().split()))

c = 0
a = 0

for i in range(0, n-1):
    for j in range(n-1, i, -1):
        if a_list[j] < a_list[j-1]:
            a = a_list[j]
            a_list[j] = a_list[j-1]
            a_list[j-1] = a
            c += 1

print(' '.join(map(str, a_list)))
print(c)

