n=int(input())
a=[int(i) for i in input().split(" ")]
x=0
flg=1
while flg:
    flg=0
    for i in range(n-1,0,-1):
        if a[i-1] > a[i]:
            a[i],a[i-1] = a[i-1],a[i]
            x+=1
            flg=1
print(" ".join([str(i) for i in a]))
print(x)
