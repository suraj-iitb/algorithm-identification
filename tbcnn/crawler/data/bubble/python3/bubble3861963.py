n=int(input())
box=list(map(int,input().split()))
count=0
for i in range(n):
    p=n-1
    while p!=i:
        if box[p]<box[p-1]:
            box[p],box[p-1]=box[p-1],box[p]
            count +=1
        p -=1
print(*box)
print(count)
