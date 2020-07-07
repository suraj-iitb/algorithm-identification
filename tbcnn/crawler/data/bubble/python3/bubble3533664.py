n = int(input())
ll = list(map(int, input().split()))


def bubble_sort(a, n):
    flag = True
    count = 0
    while flag:
        flag = False
        for i in range(n-2, -1, -1):
            if a[i] > a[i+1]:
                a[i], a[i+1] = a[i+1], a[i]
                flag = True
                count += 1
    print(" ".join(map(str, a)))
    print(count)


bubble_sort(ll, n)
