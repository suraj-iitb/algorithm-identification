n = int(input())
ns = list(map(int,input().split()))
c = 0
for i in range(n-1):
    for j in range(n-1-i):
        if ns[j] > ns[j+1]:
            ns[j],ns[j+1]=ns[j+1],ns[j]
            c+=1
print(" ".join(map(str,ns)))
print(c)
