n = int(input())
A = list(map(int, input().split()))
flag=1
count=0
while flag:
    flag=0
    j=1
    while j < n:
        if A[j]<A[j-1]:
            A[j], A[j-1]=A[j-1], A[j]
            count+=1
            flag=1
        j+=1

print(" ".join(list(map(str, A))))
print(count)
