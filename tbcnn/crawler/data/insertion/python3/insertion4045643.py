N = int(input())
working_list = list(map(int, input().split()))

print(*working_list)

for i in range(1, N):
    v = working_list[i]
    j = i - 1
    while j >= 0 and working_list[j] > v:
        working_list[j+1] = working_list[j]
        j -= 1
    working_list[j+1] = v
    print(*working_list)
