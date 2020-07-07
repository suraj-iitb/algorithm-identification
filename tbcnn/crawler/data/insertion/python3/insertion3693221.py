def p(a):
    for i in a[:-1]:
        print(i,end=' ')
    print(a[-1])


def insertion_sort(a):
    for i in range(1,len(a)):
        p(a)
        d = a[i]
        j = i-1
        while j>=0 and d<a[j]:
            a[j+1] = a[j]
            j = j-1
        a[j+1] = d


n = int(input())
l = list(map(int,input().split()))
insertion_sort(l)
p(l)
