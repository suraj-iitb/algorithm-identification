n = int(input())
A = input().split(' ')
count = 0

flag = True
while flag:
    flag = False
    i = 0

    for j in reversed(range(i + 1, n)):
        if int(A[j]) < int(A[j-1]):
            (A[j-1], A[j]) = (A[j], A[j-1])
            count += 1
            flag = True

    i += 1


print(" ".join(A))
print(count)
