def p(a):
    for i in a[:-1]:
        print(i,end=' ')
    print(a[-1])


def bubble_sort(a):
    cnt = 0
    for i in range(len(a)-1):
        for j in range(i+1,len(a))[::-1]:
            if a[j-1]>a[j]:
                cnt+=1
                tmp = a[j]
                a[j] = a[j-1]
                a[j-1] = tmp
    p(a)
    print(cnt)


n = int(input())
l = list(map(int,input().split()))
bubble_sort(l)
