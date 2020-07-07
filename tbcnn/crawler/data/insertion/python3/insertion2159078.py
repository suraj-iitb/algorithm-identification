n = int(input())
lst = list(map(int, input().split()))
for i in range(n):
    li = lst[i]
    j = i-1
    while j >= 0 and lst[j] > li:
        lst[j:j+2] = lst[j+1], lst[j]
        j -= 1
    print(*lst)
