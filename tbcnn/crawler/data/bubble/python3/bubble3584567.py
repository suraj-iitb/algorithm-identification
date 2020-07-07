def bubbleSort(a, N):
    flag = 1
    count = 0
    while flag:
        flag = 0
        for j in range(N-1, 0, -1):
            if a[j] < a[j-1]:
                a[j], a[j-1] = a[j-1], a[j]
                flag = 1
                count += 1
    return a, count

N = int(input())
a = list(map(int, input().split()))
ans, count = bubbleSort(a, N)
print(' '.join(map(str, a)))
print(count)

