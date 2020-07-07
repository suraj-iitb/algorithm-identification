input()
array = [int(x) for x in input().split()]
print(' '.join(list(str(x) for x in array)))
for i in range(1, len(array)):
    key = array[i]
    j = i - 1
    while j >= 0 and array[j] > key:
        array[j + 1] = array[j]
        j -= 1
    array[j + 1] = key
    print(' '.join(list(str(x) for x in array)))
