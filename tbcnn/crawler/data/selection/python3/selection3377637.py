def selection_sort(array):
    N = len(array)
    exc_time = 0
    for i in range(N):
        min_index = i
        for j in range(i, N):
            if array[min_index] > array[j]:
                min_index = j
        if min_index != i:
            array[i], array[min_index] = array[min_index], array[i]
            exc_time += 1
    return exc_time
    
def putsarray(array):
    for i in range(len(array) - 1):
        print(array[i], end=' ')
    print(array[-1])

if __name__ == "__main__":
    N = int(input())
    array = input().split()
    array = [int(n) for n in array]
    exc = selection_sort(array)
    putsarray(array)
    print(exc)
