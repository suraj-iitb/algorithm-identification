n = int(input())
arr = list(map(int, input().split()))
cnt = 0
for i in range(len(arr)):
    for j in range(len(arr) - 1, i, -1):
        if arr[j] < arr[j - 1]:
            arr[j], arr[j - 1] = arr[j - 1], arr[j]
            cnt += 1
print(*arr)
print(cnt)
