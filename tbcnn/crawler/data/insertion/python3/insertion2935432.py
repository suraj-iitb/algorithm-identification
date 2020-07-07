N = int(input())
arr = [int(n) for n in input().split()]

print(' '.join(map(str, arr)))
for i in range(1, N):
    v = arr[i]
    j = i - 1
    while(j >= 0 and arr[j] > v):
        arr[j + 1] = arr[j]
        j -= 1
    arr[j + 1] = v
    print(' '.join(map(str, arr)))

