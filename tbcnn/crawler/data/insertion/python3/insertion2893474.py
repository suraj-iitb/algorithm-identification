#coding:utf-8
n = int(input())
A = list(map(int, input().split()))

B = " ".join([str(num) for num in A])
print(B)

for i in range(1, n):   
    v = A[i]
    j = i - 1
    while j >= 0 and A[j] > v:
        A[j+1], A[j] = A[j], A[j+1]
        j -= 1
        
    B = " ".join([str(num) for num in A])
    print(B)


