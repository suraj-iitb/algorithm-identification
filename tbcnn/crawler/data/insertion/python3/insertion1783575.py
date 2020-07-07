n = int(input())
A = list(map(int,input().split()))
temp = 0

print(" ".join(map(str,A)))
for i in range(1,n):
    temp = A[i]
    j = i -1
    while j >=0 and A[j] > temp :
        A[j+1]=A[j]
        j-=1
    A[j+1] = temp
    print(" ".join(map(str,A)))
