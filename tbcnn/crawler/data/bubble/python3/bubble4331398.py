N = int(input())
A = [int(i) for i in input().split()]

flag = 1
perm = 0
while flag == 1:
    flag = 0
    for j in range(N-1, 0, -1):
        if A[j] < A[j-1]:
            temp = A[j]
            temp2 = A[j-1]
            A[j-1] = temp
            A[j] = temp2
            perm += 1
            flag = 1
print(" ".join(list(map(str, A))))
print(perm)
