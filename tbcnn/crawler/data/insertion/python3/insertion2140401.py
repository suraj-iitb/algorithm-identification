
def insertion_sort(a, n):
    for i in range(0, n):

        value = a[i]
        j = i - 1
        while j >= 0 and a[j] > value:
            a[j+1] = a[j]
            j -= 1
        a[j+1] = value

        # convert string to int.
        process_list = map(str, a)
        # join as string.
        print(" ".join(process_list))


num_length = int(input())
num_array = [int(x) for x in input().split()]

insertion_sort(num_array, num_length)
