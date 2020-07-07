N = int(input())
lst = list(map(int,input().split()))
cnt = 0
for i in range(N):
    for j in range(N-1, i, -1):
        if (lst[j] < lst[j-1]):
            lst[j],lst[j-1] = lst[j-1],lst[j]
            cnt += 1
print(" ".join(list(map(str, lst))))
print(cnt)
