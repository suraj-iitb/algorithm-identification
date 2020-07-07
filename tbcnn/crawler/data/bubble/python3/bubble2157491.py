def bubble_sort(A):
    flag = 1
    count = 0
    while flag:
        flag = 0
        for i in range(len(A) - 1, 0, -1):
            if A[i - 1] > A[i]:
                A[i - 1], A[i] = A[i], A[i - 1]
                flag = 1
                count += 1
    return count


def show(A):
    for i in range(len(A) - 1):
        print(A[i], end=" ")
    print(A[len(A) - 1])


n = int(input())
line = input()
A = list(map(int, line.split()))
count = bubble_sort(A)
show(A)
print(count)
