def insertion_sort(data, g, cnt):
    for i in range(1, len(data)):
        v = data[i]
        j = i-g
        while j >= 0 and data[j] > v:
            data[j+g] = data[j]
            j -= g
            cnt += 1
        data[j+g] = v
    return data, cnt


def shell_sort(data):
    cnt = 0
    G = [1]
    m = 4
    while m < len(data):
        G.append(m)
        m = 3*m + 1
    G.sort(reverse=True)
    for g in G:
        data, cnt = insertion_sort(data, g, cnt)
    return data, cnt, G


if __name__ == '__main__':
    data = []
    n = int(input())
    for _ in range(n):
        data.append(int(input()))
    data, cnt, G = shell_sort(data)
    print(len(G))
    print(*G)
    print(cnt)
    for i in range(n):
        print(data[i])

