n = int(input())
a = list(map(int, input().split()))
print(*a)
for i in range(len(a)-1):
    #print(' '.join([str(i) for i in a]))

    l = i
    j = l + 1


    while l >= 0:
        #print(l, j)
        #print(*a)
        # val1 = a[i]
        # val2 = a[j]

        #if val2 < val1:
        if a[j] < a[l]:
            # switch
            temp = a[l]
            a[l] = a[j]
            a[j] = temp
            l -= 1
            j -= 1
            #print(*a)
        else:
            break
    print(*a)
