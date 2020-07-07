# 选择排序
def selection_sort(arr):
    swap_cnt = 0
    for i in range(0, len(arr)):
        min_index = i
        for j in range(i + 1, len(arr)):
            if arr[min_index] > arr[j]:
                min_index = j
        if min_index != i:
            arr[i], arr[min_index] = arr[min_index], arr[i]
            swap_cnt += 1
    return swap_cnt

if __name__ == '__main__':
    N = int(input())
    arr = list(map(int, input().split()))
    cnt = selection_sort(arr)
    print(' '.join(map(str, arr)))
    print(cnt)
