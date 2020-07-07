n = int(input())
s = input()
A = list(map(int,s.split()))
flag = 1
cnt = 0
#####################################

for i in range(0,n):
    minj = i
    for j in range(i,n):
        if A[j] < A[minj]:
            minj = j
    if(A[i] != A[minj]):
        tmp = A[i]
        A[i] = A[minj]
        A[minj] = tmp
        cnt += 1

#####################################
for k in range(0,len(A)-1):
    print(A[k],end=" ")
print(A[len(A)-1])
print (cnt)
