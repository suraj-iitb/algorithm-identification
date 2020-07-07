n = input()
A = list(map(int, input().split()))
for index in range(len(A)):
    if index != len(A) - 1:
        print(A[index], end=" ")
    else:
        print(A[index])

for i in range(1, len(A)):
    key = A[i]
    j = i - 1
    while j >= 0 and A[j] > key:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = key
    for index in range(len(A)):
        if index == len(A) - 1:
            print(A[index])
        else:
            print(A[index], end=" ")

