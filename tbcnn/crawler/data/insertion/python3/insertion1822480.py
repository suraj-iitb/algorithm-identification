def insert(array, index):
    value = array[index]
    for i in range(index - 1, -1, -1):
        if array[i] < value:
            array[i+1] = value
            break
        array[i + 1] = array[i]
    else:
        array[0] = value

def insertion_sort(array, log=False):
    for i in range(len(array)):
        insert(array, i)
        if log:
            print(*array)

if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    insertion_sort(A, True)
