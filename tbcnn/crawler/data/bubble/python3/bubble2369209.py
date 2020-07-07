N = int(input())
a = list(map(int, input().split()))

flag = True
count = 0
while(flag):
    flag = False
    for i in range(1, N):
        if(a[-i] < a[-i-1]):
            hold = a[-i]
            a[-i] = a[-i-1]
            a[-i-1] = hold
            flag = True
            count += 1
print(" ".join(list(map(str, a))))
print(count)
