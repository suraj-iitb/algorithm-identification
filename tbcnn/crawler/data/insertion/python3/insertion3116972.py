N=int(input())
a=list(map(int, input().split()))
k=list(map(str,a))
j=' '.join(k)
print(j)
for i in range(1,N):
    v=a[i]
    j=i-1
    while a[j]>v and j>=0:
        a[j+1]=a[j]
        j -=1
    a[j+1]=v
    b=list(map(str, a))
    c=' '.join(b)
    print(c)
