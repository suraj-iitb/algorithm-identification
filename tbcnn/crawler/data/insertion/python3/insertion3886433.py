
def insertion_sort(arr, num):
    for i in range(1, num):
        v = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > v:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = v
        print(' '.join([str(c) for c in a]))


if __name__ == '__main__':
    n = int(input())
    a_str: str = input()
    a = a_str.split(' ')
    a = [int(c) for c in a]
    print(' '.join([str(c) for c in a]))
    insertion_sort(a, n)

