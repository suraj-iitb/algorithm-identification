def insertion_sort(array):
    print_array(array)
    for i in range(1,len(array)):
        key = array[i]
        j = i - 1
        while j >= 0 and array[j] > key:
            array[j+1] = array[j]
            j -= 1
        array[j+1] = key
        print_array(array)

def print_array(array):
     print(str(array)[1:-1].replace(', ', ' '))


def main():
    N = int(input())
    array = [int(s) for s in input().split(' ')]
    insertion_sort(array)

if __name__ == '__main__':
    main()
