# 入力
n = int(input().rstrip())
data = list(map(int,input().split()))

# ソート
for i in range(1, n):
    for s in range(n):
        if s != n-1:
            print(data[s], end=" ")
        else:
            print(data[s])
    min = i
    j = i-1
    while j >= 0:
        if data[min] < data[j]:
            tmp = data[j]
            data[j] = data[min]
            data[min] = tmp
            min = j
        j -= 1

for s in range(n):
    if s != n - 1:
        print(data[s], end=" ")
    else:
        print(data[s])
