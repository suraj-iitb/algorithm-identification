num = int(input())
list = list(map(int, input().split()))

for i in range(num):
    v = list[i]
    if i == 0:
        list[0] = v
    else:
        j = i - 1
        while j >= 0 and list[j] > v:
            list[j+1] = list[j]
            j -= 1
        list[j+1] = v

    result = ''
    for i in range(num):
        result += str(list[i]) + ' '

    print(result[:-1])
