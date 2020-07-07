num = int(input())

a = [int(x) for x in input().split()]

def plist(a):
    for i in range(len(a)):
        print(a[i],end="")
        if i < len(a)-1:
            print(" ",end="")
    print()
    
plist(a)
for i in range(1,num):
    tmp = a[i]
    j = i - 1
    while (j >= 0 and a[j] > tmp):
        a[j+1] = a[j]
        j -= 1
    a[j+1] = tmp
    plist(a)


