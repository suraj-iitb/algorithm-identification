N = int(input())
l = list(map(int,input().split(' ')))

i = 0
count = 0
flag =1
while flag :
    flag = 0
    for j in range(N-1,i,-1):
        if l[j-1] > l[j]:
            l[j-1],l[j] = l[j],l[j-1]
            count +=1
            flag =1
    i+=1

print(' '.join(list(map(str,l))))
print(count)

