def insertion_sort(array):
    for i in range(len(array)):
        v = array[i]
        j = i - 1

        while(j>=0 and array[j] > v):
            array[j+1] = array[j]
            j = j - 1

        array[j+1] = v

        print(' '.join(map(str, array)))

    return array

if __name__ == '__main__':
    element_number = int(input())
    input_array = list(map(int, input().split()))

    insertion_sort(input_array)
