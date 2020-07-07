n = int(input())

List = [int(i) for i in input().split()]
    
for i in range(1,n):
    for k in range(n-1):
        print(List[k], end=" ")
    print(List[n-1])
    j = i-1
    v = List[i]
    while j >= 0 and List[j] > v:
        List[j+1] = List[j]
        j-=1
    List[j+1] = v

for k in range(n-1):
    print(List[k], end=" ")
print(List[n-1])

