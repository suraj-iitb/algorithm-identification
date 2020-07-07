n=int(input())
box=list(map(int,input().split()))
print(*box)
for i in range(1,n):
    while 1:
        if i==0:break
        elif box[i]<box[i-1]:
            box[i],box[i-1]=box[i-1],box[i]
            i -=1
        else:break
    print(*box)
