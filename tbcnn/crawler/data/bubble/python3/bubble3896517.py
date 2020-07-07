n,*a = map(int,open(0).read().split())

ans = 0 

def BublbleSort(a,m):
    global ans
    flag = 1
    while flag:
        flag = 0
        for j in range(m-1,0,-1):
            if a[j] < a[j-1]:
                a[j],a[j-1]=a[j-1],a[j]
                ans += 1
                flag = 1
BublbleSort(a,n)
  
            
print(*a)

print(ans)
