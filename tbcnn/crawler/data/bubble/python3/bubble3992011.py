N = int(input())
IN = list(map(int,input().split()))
c = 0
flag = 1
while flag:
    flag = 0
    for j in range(N-1,0,-1):
        if IN[j] < IN[j-1]:
            temp = IN[j-1]
            IN[j-1] = IN[j]
            IN[j] = temp
            flag = 1
            c +=1
print(*IN)
print(c)
