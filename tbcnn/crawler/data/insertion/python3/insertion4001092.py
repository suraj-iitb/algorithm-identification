n = int(input())
array = list(map(int, input().split()))
print(' '.join([str(e) for e in array]))
for i in range(1, len(array)):
    inserting = array[i]
    j = i - 1
    while j >= 0 and array[j] > inserting:
        array[j+1] = array[j]
        j -= 1
    array[j+1] = inserting
    print(' '.join([str(ele) for ele in array]))

