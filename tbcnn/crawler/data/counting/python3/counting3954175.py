def count_sort_2(arr, max_element=10000):
    c = [0] * (max_element + 1)

    for ele in arr:
        c[ele] += 1
    for i in range(1, max_element + 1):
        c[i] += c[i - 1]

    arr_copy = list(arr)
    n = len(arr)
    for i in range(n - 1, -1, -1):
        arr[c[arr_copy[i]] - 1] = arr_copy[i]
        c[arr_copy[i]] -= 1


if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    # count_sort(arr)
    count_sort_2(arr)

    arr = map(str, arr)
    print(' '.join(arr))

