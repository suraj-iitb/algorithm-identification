n=int(input())
box=list(map(int,input().split()))
count=0
for i in range(n):
    j=box[i:].index(min(box[i:]))+i
    box[i],box[j]=box[j],box[i]
    if i!=j:
        count +=1
print(*box)
print(count)

"""n=int(input())
box=list(map(int,input().split()))
count=0
for i in range(n):
    mini=i
    for j in range(i,n):
        if box[j]<box[mini]:
            mini=j
    if box[i]>box[mini]:
        box[i],box[mini]=box[mini],box[i]
        count +=1
print(*box)
print(count)"""
