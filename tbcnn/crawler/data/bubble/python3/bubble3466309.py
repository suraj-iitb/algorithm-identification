n = int(input())
A = list(map(int,input().split()))
f = n-1
change_sum = 0

while True:
    if f == 0 :
        break
    
    for i in range(f):
        if A[i] > A[i+1]:
            v = A[i]
            A[i] = A[i+1]
            A[i+1] = v
            change_sum += 1
    f += -1    

for i in range(n):
    if i == n-1:
        print(A[i])
    else:
        print(A[i],end=' ')

print(change_sum)
