def pr(a):
    for i in range(len(a)):
        print(a[i],end="")
        if i == len(a)-1:
            print("")
        else :
            print(" ",end="")
def insertionsort(a,n):
    for i in range(1,n):
        v = a[i]
        j = i - 1
        while j >= 0 and a[j] > v:
            a[j+1] = a[j]
            j -= 1
        a[j+1] = v
        pr(a)

n = int(input())
a = input().split()
a = [int(i) for i in a]
pr(a)
insertionsort(a,n)


