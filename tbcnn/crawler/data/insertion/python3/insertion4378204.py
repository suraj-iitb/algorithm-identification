n=int(input())
#li1=list(map(int,input().split())) #li=[int(x) for x in input.split()] 
li=[int(x) for x in input().split()]

#print(li1,li2)
for i in range(n):
    v = li[i]
    j = i-1
    while j >= 0 and li[j] > v:
        li[j+1] = li[j]
        j-=1
    li[j+1] = v
    l=[str(a) for a in li]
    l=" ".join(l)
    print(l)

