n = int(input())
R = [int(x) for x in input().split()]
time = 0
flag = True
while flag:
     flag = False
     for i in reversed(range(n-1)):
        if R[i+1] < R[i]:
            R[i], R[i+1] = R[i+1], R[i]
            flag = True
            time += 1 
print(*R)
print(time)
