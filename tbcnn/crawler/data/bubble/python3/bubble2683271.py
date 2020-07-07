n = int(input())
arr = list(map(int, input().split()))

count = 0
for i in range(n):
    for j in range(n - 1, 0, -1):
        if arr[j] < arr[j-1]:
            arr[j], arr[j-1] = arr[j-1], arr[j]
            count += 1

print(*arr)
print(count)

