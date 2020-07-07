def bubble_sort(array):
    count = 0
    n = len(array)
    for i in range(n-1):
        for j in range(n-1, i, -1):
            if array[j] < array[j-1]:
                tmp = array[j]
                array[j] = array[j-1]
                array[j-1] = tmp
                count += 1

    print(" ".join(map(str,array)))
    print(count)

times = int(input())
array = list(map(int,input().split()))

bubble_sort(array)
