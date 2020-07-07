n = int(input())
R = list(map(int,input().split()))

def trace():
    for i in range(len(R)):
        if i != len(R) - 1:
            print(R[i],end=' ')
        else:
            print(R[i])

flag = True
count = 0
while flag:
    flag = False
    for i in range(1,n) [::-1]:
        if R[i] < R[i-1]:
            R[i],R[i-1] = R[i-1],R[i]
            count += 1
            flag = True

trace()

print(count)
