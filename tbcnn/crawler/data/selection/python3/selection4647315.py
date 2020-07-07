n = int(input())
arr = list(map(int, input().split()))

count = 0
for idx1 in range(0, len(arr)):
    mins = idx1
    for idx2 in range(idx1, len(arr)):
        if arr[idx2] < arr[mins]:
            mins = idx2
    
    if mins != idx1:
        arr[idx1], arr[mins] = arr[mins], arr[idx1]
        count += 1

print(" ".join(map(str, arr)), count, sep="\n")
