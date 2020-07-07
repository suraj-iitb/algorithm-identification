def counting_sort(arr):
    max_value = max(arr) + 1
    counter = [0] * max_value

    # counter[i]にiの出現数を記録
    for i in range(len(arr)):
        counter[arr[i]] += 1

    # counter[i]にi以下の数の出現数を記録
    for i in range(1, max_value):
        counter[i] += counter[i-1]

    sorted_arr = [0] * len(arr)
    for i in range(len(arr)):
        sorted_arr[counter[arr[i]] - 1] = arr[i]
        counter[arr[i]] -= 1
    
    return sorted_arr

n = int(input())
arr = list(map(int, input().split()))

print(*counting_sort(arr))


