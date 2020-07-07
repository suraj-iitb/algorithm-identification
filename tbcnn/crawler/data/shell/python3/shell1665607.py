def insertion_sort(data, g):
    global cnt
    for i in range(g, len(data)):
        v, j = data[i], i - g
        while j >= 0 and data[j] > v:
            data[j + g] = data[j]
            j = j - g
            cnt += 1
        data[j + g] = v

def shell_sort(data):
    global G
    for i in range(1, 100):
        tmp = (3 ** i - 1) // 2
        if tmp > len(data):
            break
        G.append(tmp)
    for g in list(reversed(G)):
        insertion_sort(data, g)

G, cnt = [], 0
n = int(input())
data = list(int(input()) for _ in range(n))
shell_sort(data)
print(len(G))
print(' '.join(map(str, list(reversed(G)))))
print(cnt)
print('\n'.join(map(str, data)))
