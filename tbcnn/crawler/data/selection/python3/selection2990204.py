input()
arr = list(map(int, input().split()))
count = 0
for i in range(len(arr)):
    min = arr[i]
    min_index = i
    for j in range(i+1, len(arr)):
        if arr[j] < min:
            min_index = j
            min = arr[j]
    if i != min_index:
        count += 1
        t = arr[i]
        arr[i] = min
        arr[min_index] = t
print(" ".join(map(str, arr)))
print(count)
    
