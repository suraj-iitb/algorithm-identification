N = int(input())
a_list = list(map(int, input().split()))
c = 0
for i in range(N-1):
    minj = i
    for j in range(i+1, N):
        if a_list[j] < a_list[minj]:
            minj = j
    if a_list[i] != a_list[minj]:
        a_list[i], a_list[minj] = a_list[minj], a_list[i]
        c += 1
print(' '.join(map(str, a_list)))
print(c)

