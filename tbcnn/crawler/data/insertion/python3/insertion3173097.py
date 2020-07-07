def print_list(r):
    for i in range(len(r)):
        if i != len(r)-1:
            print (r[i], end=' ')
        else:
            print(r[i])


n=int(input())
r=list(map(int,input().split()))
for i in range(0, len(r)):
        v = r[i]
        j = i-1
        while (j >= 0) & (r[j] > v):
            r[j+1] = r[j]
            j -= 1
        r[j+1] = v
        print_list(r)
