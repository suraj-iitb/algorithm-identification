n = int(input())
A = list(map(int,input().split()))
#Bubble sort
cnt = 0
flag = 1
while flag:
    flag = 0
    for j in range(n-1, 0, -1):
        if A[j] < A[j-1]:
            A[j], A[j-1] = A[j-1], A[j] #swap by Python3
            cnt +=1
            flag = 1
print(' '.join(map(str, A)))
print(cnt)

