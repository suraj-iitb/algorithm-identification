def insertsort(array):
    for i in range(1,len(array)):
        print(" ".join(list(map(str,array))))
        temp = array[i]
        j = i-1
        while j >= 0 and temp < array[j]:
            array[j+1] = array[j]
            j -= 1
        array[j+1] = temp
    return array

input()
a = insertsort(list(map(int,input().split())))
print(" ".join(list(map(str,a))))

