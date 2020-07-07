# 希尔排序
def insertion_sort(arr, step):
    swap_cnt = 0
    for i in range(step, len(arr)):
        val = arr[i]
        j = i - step
        while (j >= 0) and (arr[j] > val):
            arr[j + step] = arr[j]
            j -= step
            swap_cnt += 1
        arr[j + step] = val
    return swap_cnt

def shell_sort(arr):
    # generate G = [1, 4, 13, 40, 121, 364, 1093, ...]
    swap_cnt = 0
    G = []
    h = 1
    while h <= len(arr):
        G.append(h)
        h = 3*h + 1
    G.reverse()
    print(len(G))
    print(' '.join(map(str, G)))

    for i in G:
        swap_cnt += insertion_sort(arr, i)
    return swap_cnt

if __name__ == '__main__':
    N = int(input())
    arr = []
    for i in range(N):
        arr.append(int(input()))

    
    print(shell_sort(arr))
    for i in arr:
        print(i)

