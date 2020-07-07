n = int(input())
s = input()
A = list(map(int,s.split()))
flag = 1
cnt = 0

while(flag == 1):
    flag = 0
    for j in range(n-1,0,-1):
        if A[j] < A[j-1]:
            tmp = A[j]
            A[j] = A[j-1]
            A[j-1] = tmp
            flag = 1
            cnt += 1

for k in range(0,len(A)-1):
    print(A[k],end=" ")
print(A[len(A)-1])
print (cnt)
