
def bubblesort(a,n):
    exc = 0
    flag = True
    while flag:
        flag = False
        for j in range(n-1,0,-1):
            if a[j] < a[j-1]:
                exc += 1
                tmp = a[j]
                a[j] = a[j-1]
                a[j-1] = tmp
                flag = True
    return exc

n = int(input())
a = list(map(int,input().split()))

exc = bubblesort(a,n)
print(*a)
print(exc)
