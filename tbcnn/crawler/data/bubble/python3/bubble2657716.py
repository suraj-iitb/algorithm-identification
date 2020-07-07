n = int(input())
a = list(map(int, input().split()))

def bubbleSort(a, n):
    flag = 1
    i = 0
    count = 0
    while flag:
        flag = 0
        for j in range(n-1, i, -1):
            if a[j] < a[j-1]:
                a[j],a[j-1] = a[j-1],a[j]
                flag = 1
                count += 1
        i += 1
    print(*a)
    print(count)
                   
bubbleSort(a,n)
