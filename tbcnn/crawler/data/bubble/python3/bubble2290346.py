#3.3

N = int(input())
a = list(map(int, input().split()))

flag = 1
swapcount = 0
while flag == 1:
    flag = 0
    for i in range(0, N-1):
        if a[i] > a[i + 1]:
            tmp = a[i];
            a[i] = a[i + 1]
            a[i + 1] = tmp
            flag = 1
            swapcount += 1

print(' '.join(map(str, a)))
print(swapcount)


            
