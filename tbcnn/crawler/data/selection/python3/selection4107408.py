# Selection Sort
N = int(input())
lst = list(map(int,input().split()))
cnt = 0
for i in range(N):
    minj = i
    for j in range(i, N):
        if (lst[j] < lst[minj]):
            minj = j
    lst[i],lst[minj] = lst[minj],lst[i]
    if (i != minj):
        cnt += 1
print(" ".join(list(map(str, lst))))
print(cnt)
