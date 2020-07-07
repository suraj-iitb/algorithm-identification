n=int(input())
s=input().split(' ')

flag=1
m=0

while flag:
    flag=0
    for j in range(1,n):
        j=n-j
        if int(s[j])<int(s[j-1]):
            a=s[j]
            s[j]=s[j-1]
            s[j-1]=a
            m+=1
            flag=1

print(' '.join(s))
print(m)
