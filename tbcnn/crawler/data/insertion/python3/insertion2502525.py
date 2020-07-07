def print_1(array):
    for i in range(len(array)):
        if i == len(array) - 1:
            print(array[i])
        else:
            print(array[i], end=" ")

N = int(input())
A = [int(n) for n in input().split()]
print_1(A)
for i in range(1, N):
    v = A[i]
    j = i - 1
    while j >= 0 and A[j] > v:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = v
    print_1(A)
