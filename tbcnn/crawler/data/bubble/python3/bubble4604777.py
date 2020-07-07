def bubbleSort(a, n):
    flag = 1
    cnt = 0
    i = 0
    while flag:
        flag = 0
        for j in reversed(range(i+1, n)):
            if a[j] < a[j-1]:
                a[j], a[j-1] = a[j-1], a[j]
                flag = 1
                cnt += 1
        i += 1
    print(' '.join(map(str, a)))
    print(cnt)

n = int(input())
a = list(map(int, input().split()))

bubbleSort(a, n)
