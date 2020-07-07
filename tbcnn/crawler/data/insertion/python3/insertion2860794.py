N = int(input())
ary = list(map(int, input().split(' ')))

def insertion_sort(array, n):
    print_out(array)
    for i in range(1,n):
        v = array[i]
        j = i-1
        while(j>=0 and array[j] > v):
            array[j+1] = array[j]
            j -= 1
        array[j+1] = v
        print_out(array)

def print_out(array):
    array_str = [str(i) for i in array]
    print(" ".join(array_str))

insertion_sort(ary, N)

