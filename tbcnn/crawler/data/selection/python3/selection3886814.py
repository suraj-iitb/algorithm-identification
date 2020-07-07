def pintarr(arr):
    arr = [str(c) for c in arr]
    print(' '.join(arr))


def selecsort(arr, total):
    count = 0
    for i in range(total):
        minj = i
        for j in range(i, total):
            if arr[j] < arr[minj]:
                minj = j
        arr[i], arr[minj] = arr[minj], arr[i]
        if i != minj:
            count += 1
    pintarr(arr)
    print(count)


if __name__ == '__main__':
    t = int(input())
    a = input()
    a = [int(c) for c in a.split(' ')]
    selecsort(a, t)
