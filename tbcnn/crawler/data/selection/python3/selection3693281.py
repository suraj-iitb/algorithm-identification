def p(a):
    for i in a[:-1]:
        print(i,end=' ')
    print(a[-1])


def selection_sort(a):
    cnt = 0
    for i in range(len(a)-1):
        fl = 0
        min = i
        for j in range(i+1,len(a)):
            if a[j]<a[min]:
                fl=1
                min = j
        cnt+=fl
        tmp = a[min]
        a[min] = a[i]
        a[i] = tmp
    p(a)
    print(cnt)


n = int(input())
l = list(map(int,input().split()))
selection_sort(l)
