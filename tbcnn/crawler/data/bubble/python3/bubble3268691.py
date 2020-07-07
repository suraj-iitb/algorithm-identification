n = int(input())
a = [int(x) for x in input().split()]


def bubblesort(n,a):
    count = 0
    flag = 1
    while flag:
        flag = False
        for i in reversed(range(1,n)):
            if a[i-1] > a[i]:
                a[i], a[i-1] = a[i-1], a[i]
                flag = True
                count += 1
    return a, count

a, count = bubblesort(n,a)
print(' '.join(map(str, a)))
print(count)
