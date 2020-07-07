
def insert_sort(A):
    array = A[:]
    for i in range(1, len(array)):
        print(' '.join(array))
        v = array[i]
        j = i - 1

        while j >= 0 and int(array[j]) > int(v):
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = v
    return array

_, A = input(), input().split()
print(' '.join(insert_sort(A)))
