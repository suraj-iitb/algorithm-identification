#coding: utf-8

n = int(input())
a = list(map(int, input().split()))

def view():
    print(str(a[0]), end = '')
    for k in range(1, n):
        print(' {}'.format(a[k]), end = '')
    print('')
    
for i in range(1, n):
    view()
    v = a[i]
    j = i - 1
    while j >= 0 and a[j] > v:
        a[j + 1] = a[j]
        j -= 1
    a[j + 1] = v
view()
