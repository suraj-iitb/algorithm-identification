def bubbleSort(A,N):
    flag = True
    count = 0
    while flag:
        flag = False
        for j in range(N-1,0,-1):
            if A[j] < A[j-1]:
                v = A[j]
                A[j] = A[j-1]
                A[j-1] = v
                count += 1
                flag = True
    return count

n = int(input())
x = input().split()
y=[]
for i in range(n):
    y += [int(x[i])]
    
count = bubbleSort(y,n)
for j in range(n-1):
    print(y[j],end=' ')
print(y[n-1])
print(count)

