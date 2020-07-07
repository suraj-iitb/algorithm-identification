n = int(input())

array = input().split()

intarr = [int(x) for x in array]
for x in intarr:
    if x == intarr[-1]:
        print(x)
    else:
        print(x,end=' ')


for c in range(1,n):
    v = intarr[c]
    j = c-1
    while j>=0 and intarr[j]>v:
        intarr[j+1] = intarr[j]
        j -= 1
    intarr[j+1] = v
    for x in intarr:
        if x == intarr[-1]:
            print(x)
        else:
            print(x, end=' ')
