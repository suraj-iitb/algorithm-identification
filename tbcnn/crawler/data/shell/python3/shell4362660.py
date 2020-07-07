import copy


def insertion_sort(arr, n, g, cnt):
    for i in range(g, n):
        v = arr[i]
        k = i - g
        while k >= 0 and arr[k] > v:
            arr[k + g] = arr[k]
            k = k - g
            cnt += 1
        arr[k + g] = v
    return arr, cnt


def shell_sort(arr, n, G):
    A = copy.deepcopy(arr)
    c = 0
    for i in G:
        A, c = insertion_sort(A, n, i, c)
    return A, c


n = int(input())
A = []
for i in range(n):
    A.append(int(input()))
G = [1]
h = 1
while h * 3 + 1 <= n:
    h = 3 * h + 1
    G.append(h)

a, cnt = shell_sort(A, n, G[::-1])

print(len(G))
print(*G[::-1])
print(cnt)
for i in a:
    print(i)

