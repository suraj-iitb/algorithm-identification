def selection(n, data):
    __count = 0
    for i in range(n):
        min_i = i
        for j in range(i+1, n):
            if data[min_i] > data[j]:
                min_i = j
        tmp = data[i]
        data[i] = data[min_i]
        data[min_i] = tmp
        if min_i != i:
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
    data, count = selection(n, data)
    show(data, count)
