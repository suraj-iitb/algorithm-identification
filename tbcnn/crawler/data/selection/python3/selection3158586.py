n = int(input())
list_n = list((map(int, input().split())))

def selectionSort(list_a, n):
    count = 0
    for i in range(0, n):
        minj = i
        for j in range(i, n):
            if list_a[j] < list_a[minj]:
                minj = j
        (list_a[i], list_a[minj]) = (list_a[minj], list_a[i])
        if minj != i:
            count += 1
    return list_a,count

list_n, count = selectionSort(list_n, n)
print(" ".join(str(number) for number in list_n))
print(count)

