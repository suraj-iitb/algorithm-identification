N = int(input())
A = [int(i) for i in input().split()]
flag = 1
p = 0
while flag :
    flag = 0
    for j in range(N-1,0,-1) :
        if A[j] < A[j-1] :
            t = A[j]
            A[j] = A[j-1]
            A[j-1] = t
            p += 1
            flag = 1
for i in range(N) :
    if i == N-1 :
        print(A[i])
    else :
        print(A[i],end=" ")
print(p)




