n = int(input())
array = list(map(int, input().split()))

flag = 1
count = 0
while flag:
    flag = 0
    for i in range(1, n)[::-1]:
        if array[i] < array[i-1]:
            array[i], array[i-1] = array[i-1], array[i]
            flag = 1
            count += 1
print(' '.join(list(map(str, array))))
print(count)

