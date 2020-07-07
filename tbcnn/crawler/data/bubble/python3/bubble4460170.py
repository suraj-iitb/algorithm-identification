def bubblesort(A,N):
    flag = 1 
    count = 0
    while flag:
        flag = 0
        for j in range(N-1,0,-1):
           if A[j] < A[j-1]:
                ho = A[j]
                A[j] = A[j-1]
                A[j-1] = ho
                flag = 1
                count += 1
    return A,count

n = int(input())
a = [ int(i) for i in input().split()]
b , count = bubblesort(a,n)
for i in range(len(b)):
    if i == len(b)-1:
        print(b[i])
    else:
        print(b[i],end=' ')
print(count)
