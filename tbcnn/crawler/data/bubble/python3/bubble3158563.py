n = int(input())
list_n = list((map(int, input().split())))


def bubbleSort(list_a, n):
    count = 0
    flag = 1
    while flag:
        flag = 0
        for j in list(range(1,n))[::-1]:
            if list_a[j] < list_a[j-1]:
                (list_a[j], list_a[j-1]) = (list_a[j-1], list_a[j])
                count += 1
                flag = 1
    return list_a,count
list_n,count = bubbleSort(list_n, n)
print(" ".join(str(number) for number in list_n))
print(count)

