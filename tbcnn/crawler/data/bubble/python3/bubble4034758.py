input()
A = [int(i) for i in input().split()]
flag = 1
n = 0
while flag:
    flag = 0
    for j in range(len(A) - 1, 0, -1):
        # print("debug: j = {0}".format(j))
        if A[j] < A[j - 1]:
            A[j], A[j - 1] = A[j - 1], A[j]
            flag = 1
            n += 1
print(" ".join(map(str, A)))
print(n)

