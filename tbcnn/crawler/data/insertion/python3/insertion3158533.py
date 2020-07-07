n = int(input())
list_n = list((map(int, input().split())))
def insertionSort(list_a, n):
    for i in range(1,n):
        v = list_a[i]
        j = i - 1
        while j >= 0 and list_a[j] > v:
            list_a[j+1] = list_a[j]
            j -= 1
        list_a[j+1] = v
        print(" ".join([str(number) for number in list_a]))
print(" ".join([str(number) for number in list_n]))
insertionSort(list_n, n)

