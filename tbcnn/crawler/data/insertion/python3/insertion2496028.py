n=int(input())
z=list(map(int,input().split()))
print(' '.join(list(map(str,z))))
for i in range(1,n):
    v=z[i]
    j=i-1
    while j>=0 and z[j]>v:
        z[j+1]=z[j]

        j-=1
        z[j+1]=v
    print(' '.join(list(map(str, z))))
