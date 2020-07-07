
def print_result(arr, n):
    for i in range(n):
        if i > 0:
            print(' ', end='')
        print(arr[i], end='')
    print('\n', end='')


def bubble_sort(arr, n):
    flag = True
    i = 0
    sw_count = 0
    while flag:
        flag = False
        for j in range(n-1, i, -1):
            if arr[j] < arr[j-1]:
                arr[j], arr[j-1] = arr[j-1], arr[j]
                flag = True
                sw_count += 1
        i += 1
    return sw_count


n = eval(input())
arr = [eval(x) for x in input().split()]
sw = bubble_sort(arr, n)
print_result(arr, n)
print(sw)


