n = int(input())
sortlist = list(map(int,input().split()))

print(' '.join(map(str, sortlist)))
for i in range(1,n):
    temp = sortlist[i]
    if temp < sortlist[i-1]:
        j = i
        while True:
            sortlist[j] = sortlist[j-1]
            j -= 1
            if j ==0 or temp >= sortlist[j-1]:
                break
        sortlist[j] = temp
        print(' '.join(map(str, sortlist)))
    else:
        print(' '.join(map(str, sortlist)))


