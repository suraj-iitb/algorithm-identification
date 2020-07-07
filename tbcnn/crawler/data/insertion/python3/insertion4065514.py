def print_list(a):
    out = ''
    for ai in a:
        out += str(ai) + ' '
    else:
        out = out[:-1]
    print(out)

def insertion_sort(n, a):
    for i in range(1, n):
        print_list(a)
        v = a[i]
        sorted_list_idx = i
        while sorted_list_idx > 0 and a[sorted_list_idx - 1] > v:
            a[sorted_list_idx] = a[sorted_list_idx - 1]
            sorted_list_idx -= 1
        a[sorted_list_idx] = v
    return a


n = int(input())
a = list(map(int, input().split(' ')))

a = insertion_sort(n, a)

print_list(a)
