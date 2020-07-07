
import functools


def pretty_print(arr: [int]):
    return functools.reduce(lambda a, b: f'{a} {b}', arr)


def custom_sort(arr: [int]):
    print(pretty_print(arr))
    for i in range(1, len(arr)):
        val = arr[i]
        # print(f'val is {val}')
        j = i - 1
        # print(j >= 0, arr[j] > val)
        while j >= 0 and arr[j] > val:
            # print(f'\tj is {j}')
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = val
        print(pretty_print(arr))
    return arr


length = input()
array: [int] = list(map(lambda n: int(n), input().split(' ')))
# print(type(array[0]))

custom_sort(array)
