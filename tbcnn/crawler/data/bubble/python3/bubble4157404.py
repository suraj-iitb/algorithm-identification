def babble_sort(n, data):
    __count = 0
    for i in range(n-1):
        for j in range(n-i-1):
            if data[j] > data[j+1]:
                tmp = data[j+1]
                data[j+1] = data[j]
                data[j] = tmp
                __count += 1
    return data, __count

def show(data, count):
    for i in range(len(data)):
        if i != (len(data)-1):
            print(data[i], end = " ")
        else:
            print(data[i])
    print(count)

if "__main__" == __name__:
    n = int(input())
    data = list(map(int, input().rsplit()))
    data, count = babble_sort(n, data)
    show(data, count)
