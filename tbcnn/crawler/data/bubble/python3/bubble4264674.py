N = int(input())
A = input().split()
A = [int(x) for x in A]

c = 0 #交換回数
flag = 1
while flag:
    flag = 0
    j = N-1
    while j >= 1:
        if A[j] < A[j-1]:
            c +=1 
            v = A[j]
            A[j] = A[j-1]
            A[j-1] = v
            flag = 1
        j -=1

A = [str(x) for x in A]
print(" ".join(A))
print(c)
