N = int(input())
lst = list(map(int, input().split()))
print(" ".join(list(map(str, lst))))
for i in range(1, N):
    v = lst[i]
    j = i - 1
    while (j >= 0 and lst[j] > v):
        lst[j+1] = lst[j]
        j -= 1
    lst[j+1] = v
    print(" ".join(list(map(str, lst))))

