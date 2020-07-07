A=int(input())
B=[int(i) for i in input().split()]
flag=True
s=0
while flag:
    flag=False
    for j in range(1,A):
        if B[j]<B[j-1]:
            B[j],B[j-1]=B[j-1],B[j]
            flag=True
            s+=1
for i in range(A):
    if i!=A-1:
        print(B[i],end=" ")
    else:
        print(B[i])
print(s)

