
def selection_sort(arr, n):
    mini = 0
    sw = 0
    for i in range(n-1):
        mini = i
        for j in range(i, n):
            if arr[j] < arr[mini]:
                mini = j
        arr[i], arr[mini] = arr[mini], arr[i]

        if i != mini:
            sw += 1

    return sw



def print_result(arr, n):
    for i in range(n):
        if i > 0:
            print(' ', end='')
        print(arr[i], end='')
    print('\n', end='')



n = eval(input())
arr = [eval(x) for x in input().split()]
sw = selection_sort(arr, n)
print_result(arr, n)
print(sw)

