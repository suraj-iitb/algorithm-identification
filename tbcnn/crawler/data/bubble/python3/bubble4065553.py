def print_list(a):
    out = ''
    for ai in a:
        out += str(ai) + ' '
    else:
        out = out[:-1]
    print(out)

def bubble_sort(a, n):
    flag = True
    cnt = 0
    while flag:
        flag = False
        for j in range(n - 1, 0, -1):
            if a[j] < a[j - 1]:
                tmp = a[j]
                a[j] = a[j - 1]
                a[j - 1] = tmp
                cnt += 1
                flag = True
    
    print_list(a)
    print(str(cnt))
    return a



n = int(input())
a = list(map(int, input().split(' ')))

a = bubble_sort(a, n)

