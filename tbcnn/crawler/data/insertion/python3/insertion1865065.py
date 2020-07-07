n = int(input())
arr = []
s = input().split()
for i in range(n):
    arr.append(int(s[i]))
for i in range(n):
    k = arr[i]
    j = i - 1
    while j >= 0 and arr[j] > k:
        arr[j+1] = arr[j]
        j -= 1
    arr[j+1] = k
    for i in range(n):
        if i == n-1:
            print(arr[i])
        else:
            print(arr[i], end=" ")
