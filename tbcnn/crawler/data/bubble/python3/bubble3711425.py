# 冒泡排序
def bubble_sort(arr):
    no_swap = True
    swap_cnt = 0
    for i in range(len(arr), 0, -1):
        if not no_swap:
            break
        for j in range(0, i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swap_cnt += 1
            no_swap = True
    return swap_cnt


if __name__ == '__main__':
    N = int(input())
    arr = list(map(int, input().split()))
    cnt = bubble_sort(arr)
    print(' '.join(map(str, arr)))
    print(cnt)
