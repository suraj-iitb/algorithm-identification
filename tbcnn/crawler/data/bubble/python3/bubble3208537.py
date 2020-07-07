N = int(input())
A = [int(i) for i in input().split()]

# A = [5, 3, 2, 4, 1]

def bubbleSort(arr):
    arr_len = len(arr)
    flg = True
    cnt = 0
    while flg:
        flg = False
        for i in range(arr_len -1, 0, -1):
            if arr[i] < arr[i-1]:
                arr[i], arr[i-1] = arr[i-1], arr[i]
                flg = True
                cnt = cnt + 1
                
    print(' '.join([str(x) for x in arr]))
    print(cnt)

bubbleSort(A)
