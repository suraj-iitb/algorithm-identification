n = int(input())
*lst, = map(int, input().split())

for i in range(1, n):
    print(*lst)
    v = lst[i]
    j = i - 1

    while j>=0 and lst[j]>v:
        lst[j+1] = lst[j]
        j -= 1

    lst[j+1] = v
    
print(*lst)
