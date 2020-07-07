N = int(input())
b = input().split()
a = [int(n) for n in b]

c = 0
flag = 1
while flag:
    flag = 0
    for j in range(1,N):
        if a[j] < a[j-1]:
            v = a[j]
            a[j] = a[j-1]
            a[j-1] = v
            c +=1
            flag =1
print(" ".join([str(n) for n in a]))
print(c)
