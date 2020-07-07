#60
#ALDS1_2_A
n=int(input())
*l,=map(int,input().split())
flag=0

for i in range(n):
    for j in range(n-1):
        if l[j+1]<l[j]:
            l[j],l[j+1]=l[j+1],l[j]
            flag+=1
print(*l)
print(flag)
