n = int(input())
*array, = list(map(int, input().split())) 


def bubble_sort(a):
    c = 0
    flag = 1
    i = 0
    while flag:
        flag = 0

        # range(a, b, c) jがbになったときに処理中断する
        for j in range(n-1, i, -1):
            if a[j] < a[j-1]:

                a[j], a[j-1] = a[j-1], a[j]
                c += 1
                flag = 1

        i += 1

    print(*a)
    print(c)


bubble_sort(array)





