n = int(input())
a = list(map(int, input().split()))
numSwap = 0

for i in range(n):
    for j in range(n-1, i, -1):
        if a[j-1] > a[j]:
            a[j-1], a[j] = a[j], a[j-1]
            numSwap += 1
        # print('i = '+str(i)+': '+':::j = '+str(j)+': '+ str(a))
a = [str(s) for s in a]
print(' '.join(a))
print(numSwap)
