#coding: UTF-8

a = int(input())
N = list(map(int, input().split()))

c = 0

for i in range(a - 1):
    for j in range(a-1, i,-1):
        if N[j] < N[j - 1]:
            c+=1
            tmp = N[j]
            N[j] = N[j - 1]
            N[j - 1] = tmp

for i in range(a - 1):
    print(N[i],end=' ')
print(N[a-1]);
print(c);
