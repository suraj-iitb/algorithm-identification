def print_list(a):
    out = ''
    for ai in a:
        out += str(ai) + ' '
    else:
        out = out[:-1]
    print(out)

def selection_sort(a, n):
    cnt = 0
    for i in range(0, n):
        minj = i
        for j in range(i, n):
            if a[j] < a[minj]:
                minj = j
        if i != minj:
            tmp = a[i]
            a[i] = a[minj]
            a[minj] = tmp
            cnt += 1

    print_list(a)
    print(str(cnt))
    return a

n = int(input())
a = list(map(int, input().split(' ')))

a = selection_sort(a, n)
