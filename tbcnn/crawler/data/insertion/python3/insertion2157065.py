def insert_sort(A):
    for i in range(1, len(A)):
        k = A[i]
        j = i - 1
        while j >= 0 and A[j] > k:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = k
        show(A)

def show(A):
    for i in range(len(A) - 1):
        print(A[i], end=" ")
    print(A[len(A) - 1])

n =  int(input())
line = input()
A = list(map(int, line.split()))
show(A)
insert_sort(A)
