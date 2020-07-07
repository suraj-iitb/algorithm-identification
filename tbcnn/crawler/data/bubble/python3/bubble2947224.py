def bubble_sort(l):
    flag = 1
    count = 0
    while flag == 1:
        flag = 0
        j = len(l) - 1
        while(0 < j):
            if l[j] < l[j-1]:
                swap = l[j]
                l[j] = l[j-1]
                l[j-1] = swap
                count = count + 1
                flag = 1
            j = j - 1
    return l,count


n = int(input())

l = list(map(int,input().split()))

if len(l) != n:
    print("Error")
    exit()

l,count = bubble_sort(l)

for i in range(len(l)):
    if i == (len(l) - 1):
        print(l[i])
    else:
        print(l[i],end='')
        print(" ",end='')
print(count)

