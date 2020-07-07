import sys


def print_arr(arr):
    ln = ''
    for v in arr:
        ln += str(v) + ' '

    ln = ln.strip()
    print(ln)

def insertion_sort(arr):
    for i in range(1, len(arr)):
        print_arr(arr)
        v = arr[i]
        j = i-1
        while j >= 0 and arr[j] > v:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = v

    print_arr(arr)

input0 = sys.stdin.readline()
input_sample = sys.stdin.readline()
# input_sample = "5 2 4 6 1 3"
input = input_sample.split(" ")
input = [int(i) for i in input]
insertion_sort(input)
