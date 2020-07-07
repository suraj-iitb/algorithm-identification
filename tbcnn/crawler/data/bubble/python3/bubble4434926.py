def bubbleSort(l, n):
    flag = 1
    count = 0
    while flag:
        flag = 0
        for i in range(n-1, 0, -1):
            if l[i] < l[i-1]:
                temp = l[i]
                l[i] = l[i-1]
                l[i-1] = temp
                count += 1
                flag = 1
    return count

n = int(input())
l = list(map(int, input().split()))
c = bubbleSort(l, n)
print(" ".join(map(str, l)))
print(c)

